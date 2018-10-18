#include <bits/stdc++.h>
using namespace std;

#ifdef DEBUG
    #define dbg(...) fprintf(stderr, __VA_ARGS__)
#else
    #define dbg(...)
#endif

const int N_MAX = 105, K_MAX = 12, MOD = (int) 1e8;
int N[2], K[2];
long long ans, dp[N_MAX][N_MAX][2][K_MAX];

int main()
{
    cin >> N[0] >> N[1] >> K[0] >> K[1];
    dp[1][0][0][1] = dp[0][1][1][1] = 1;
    for (int n = 1; n <= N[0]+N[1]; ++n) {
        for (int n0 = 0, n1 = n-n0; n0 <= N[0]; ++n0, --n1) {
            for (int k = 1; k <= K[0]; ++k) {
                dp[n0+1][n1][0][k+1] += dp[n0][n1][0][k];
                dp[n0+1][n1][0][k+1] %= MOD;
                dp[n0][n1+1][1][1] += dp[n0][n1][0][k];
                dp[n0][n1+1][1][1] %= MOD;
            }
            for (int k = 1; k <= K[1]; ++k) {
                dp[n0+1][n1][0][1] += dp[n0][n1][1][k];
                dp[n0+1][n1][0][1] %= MOD;
                dp[n0][n1+1][1][k+1] += dp[n0][n1][1][k];
                dp[n0][n1+1][1][k+1] %= MOD;
            }
        }
    }
    for (int man = 0; man < 2; ++man) {
        for (int k = 1; k <= K[man]; ++k) {
            ans += dp[N[0]][N[1]][man][k];
            ans %= MOD;
        }
    }
    cout << ans << '\n';

    return 0;
}
