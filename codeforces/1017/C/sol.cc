#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <vector>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <queue>
#include <ctime>
#include <cassert>
#include <complex>
#include <string>
#include <cstring>
using namespace std;

#ifdef DEBUG
	#define eprintf(...) fprintf(stderr, __VA_ARGS__)
#else
	#define eprintf(...)
#endif

typedef long long ll;
typedef pair<int, int> pii;

int main()
{
    int n, v, k, x;
    cin >> n;
    v = n+1, k = 1;
    for (int i = 1; i <= n && i < v; ++i) {
        x = ceil((double)n/i) + i;
        if (x < v) {
            v = x;
            k = i;
        }
    }
    while (n > 0) {
        for (int i = 1; i <= k; ++i) {
            if (n-k+i > 0)
                cout << n-k+i << ' ';
        }
        n -= k;
    }
    cout << '\n';
	return 0;
}
// Time: O(), Space: O()
