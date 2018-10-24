#include <iostream>
#include <iomanip>
#include <string>
#include <sstream>
#include <fstream>
#include <cassert>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <numeric>
#include <utility>
#include <vector>
#include <queue>
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <bitset>
#include <complex>
#include <climits>
using namespace std;

#ifdef DEBUG
    #define dbg(...) fprintf(stderr, __VA_ARGS__)
#else
    #define dbg(...)
#endif

const int NMAX = 55;
int n, l;
int a[NMAX];
int cache[NMAX][NMAX];

int solve(int l, int r)
{
    if (r-l < 2) return 0;
    if (cache[l][r]) return cache[l][r];
    int ans = INT_MAX;
    for (int cut = l+1; cut < r; ++cut)
        ans = min(ans, a[r]-a[l]+solve(l, cut)+solve(cut, r));
    return cache[l][r] = ans;
}

int main()
{
    while (true) {
        scanf("%d", &l);
        if (l == 0) return 0;
        memset(a, 0, sizeof(a));
        memset(cache, 0, sizeof(cache));
        scanf("%d", &n);
        for (int i = 1; i <= n; ++i)
            scanf("%d", &a[i]);
        a[n+1] = l;
        printf("The minimum cutting is %d.\n", solve(0, n+1));
    }
}
// Time: O(), Space: O()
