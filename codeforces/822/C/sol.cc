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
#include <climits>
using namespace std;

#ifdef DEBUG
    #define dbg(...) fprintf(stderr, __VA_ARGS__)
#else
    #define dbg(...)
#endif

const int N_MAX = 200000 + 5;
const long long C_MAX = 2e9 + 9;
int n, x, l, r, c, t, y, a, b;
long long best[N_MAX], ans = 2 * C_MAX;
vector<tuple<int, int, int, int>> queries;

int main()
{
    scanf("%d %d", &n, &x);
    for (int i = 0; i < n; ++i) {
        scanf("%d %d %d", &l, &r, &c);
        queries.push_back({l, 1, r, c});
        queries.push_back({r, 2, l, c});
    }
    sort(queries.begin(), queries.end());
    fill(best, best+N_MAX, C_MAX);
    for (int i = 0; i < queries.size(); ++i) {
        tie(a, t, b, c) = queries[i];
		dbg("%d %d %d %d\n", a, t, b, c);
        if (t == 1) {
            y = x - (b - a + 1);
            if (y >= 0) {
                ans = min(ans, 1LL*best[y] + 1LL*c);
            }
        } else {
            y = a - b + 1;
            if (y <= x) {
                best[y] = min(best[y], 1LL*c);
            }
        }
    }
    if (ans >= C_MAX) {
        puts("-1");
    } else {
        printf("%lld\n", ans);
    }
}
