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
    int t, n, p;
    cin >> t;
    while (t--) {
        cin >> n >> p;
        int k = 2 * n + p;
        for (int i = 1; i <= n && k; ++i) {
            for (int j = i+1; j <= n && k; ++j) {
                cout << i << ' ' << j << '\n';
                --k;
            }
        }
    }
	return 0;
}
// Time: O(), Space: O()
