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
using namespace std;

#ifdef DEBUG
    #define dbg(...) fprintf(stderr, __VA_ARGS__)
#else
    #define dbg(...)
#endif

const int NMAX = 100005;
int T, N, K, ans;
int A[NMAX];
map<pair<int, int>, int> cache;

void solve(int l, int r, int v)
{
    if (l > r || v >= ans) {
        ans = min(ans, v);
        return;
    }
    // dbg("l: %d, r: %d, v: %d\n", l, r, v);
    auto par = make_pair(l, r);
    if (cache[par] == 0 || cache[par] > v) {
        cache[par] = v;
        if (A[l] == A[r])
            solve(l+1, r-1, v);
        else {
            solve(l+1, r, v+1);
            solve(l, r-1, v+1);
        }
    }
}

int main()
{
    scanf("%d", &T);
    for (int t = 1; t <= T; ++t) {
        memset(A, 0, sizeof(A));
        cache.clear();

        scanf("%d %d", &N, &K);
        for (int i = 0; i < N; ++i)
            scanf("%d", &A[i]);

        ans = K + 1;
        solve(0, N-1, 0);

        printf("Case %d: ", t);
        dbg("%d\n", ans);
        if (ans > K) {
            printf("Too difficult\n");
        } else if (!ans) {
            printf("Too easy\n");
        } else {
            printf("%d\n", ans);
        }
    }
}
// Time: O(), Space: O()
