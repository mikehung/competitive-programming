#include <bits/stdc++.h>
using namespace std;

const int N = 1000 + 7, MOD = 998244353;

int dp[N][2 * N][4];

void add(int &a, int b)
{
    a = (a + b) % MOD;
}

bool full(int mask)
{
    return (mask == 0 || mask == 3);
}

int update(int mask, int nmask)
{
    int cnt = __builtin_popcount(mask ^ nmask);
    if (cnt == 0) return 0;
    if (cnt == 2) return (full(mask) ? 1 : 2);
    return (!full(mask) ? 0 : 1);
}

int main() {
    int n, k;
    scanf("%d%d", &n, &k);

    dp[1][1][0] = dp[1][1][3] = dp[1][2][1] = dp[1][2][2] = 1;
    for (int i = 1; i < n; ++i){
        for (int j = 0; j <= k; ++j) {
            for (int mask = 0; mask < 4; ++mask) {
                for (int nmask = 0; nmask < 4; ++nmask) {
                    add(dp[i + 1][j + update(mask, nmask)][nmask], dp[i][j][mask]);
                }
            }
        }
    }

    int ans = 0;
    for (int mask = 0; mask < 4; ++mask) {
        add(ans, dp[n][k][mask]);
    }

    printf("%d\n", ans);
}
