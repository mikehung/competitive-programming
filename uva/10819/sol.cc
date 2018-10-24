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

const int M_MAX = 1e4+500;
int m, n, p, f;
int cur_ok[M_MAX], cur_f[M_MAX];

int main()
{
    while (scanf("%d %d", &m, &n) == 2) {
        memset(cur_ok, 0, sizeof(cur_ok));
        memset(cur_f, 0, sizeof(cur_f));

        cur_ok[0] = 1;
        while (n--) {
            scanf("%d %d", &p, &f);
            for (int i = m+200; i >= 0; --i) {
                if (!cur_ok[i]) continue;
                int np = i + p;
                if (np <= m+200 && cur_f[np] < cur_f[i] + f) {
                    cur_ok[np] = 1;
                    cur_f[np] = cur_f[i] + f;
                }
            }
        }

        int ans = 0;
        for (int i = 0; i <= m+200; ++i) {
            if (i > m && i <= 2000) continue;
            if (cur_f[i] > ans)
                ans = cur_f[i];
        }
        printf("%d\n", ans);
    }
}
// Time: O(), Space: O()
