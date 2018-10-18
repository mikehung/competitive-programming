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
    int n, a, b, c, d;
    cin >> n;
    vector<pair<int, int>> A(n);
    for (int i = 0; i < n; ++i) {
        cin >> a >> b >> c >> d;
        A[i] = make_pair(-a-b-c-d, i+1);
    }
    sort(A.begin(), A.end());
    for (int i = 0; i < n; ++i) {
        if (A[i].second == 1)
            cout << i+1 << '\n';
    }
	return 0;
}
// Time: O(), Space: O()
