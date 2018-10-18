#include <bits/stdc++.h>
using namespace std;

#ifdef DEBUG
    #define dbg(...) fprintf(stderr, __VA_ARGS__)
#else
    #define dbg(...)
#endif

const int MAX = 105;
const long long C_MAX = 1e13;
int n, m, K, c[MAX], res[MAX][MAX][2];
long long ans = C_MAX, cost[MAX][MAX], dp[MAX][MAX][MAX];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> m >> K;
    for (int i = 1; i <= n; ++i) {
        cin >> c[i];
    }
    for (int i = 0; i < MAX; ++i) {
        for (int j = 0; j < MAX; ++j) {
            for (int k = 0; k < MAX; ++k)
                dp[i][j][k] = C_MAX;
        }
    }
    dp[0][0][0] = 0;
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            cin >> cost[i][j];
            if (c[i]) {
                cost[i][j] = 0;
            }
        }
    }
    for (int i = 1; i <= n; ++i) {
        int lo = c[i] ? c[i] : 1;
        int hi = c[i] ? c[i] : m;
        for (int c = lo; c <= hi; ++c) {
            for (int k = 0; k < i; ++k) {
                int c0 = res[i-1][k][0];
                int c1 = res[i-1][k][1];
                if (c != c0) {
                    dp[i][c][k+1] = min(dp[i][c][k+1], dp[i-1][c0][k] + cost[i][c]);
                } else {
                    dp[i][c][k+1] = min(dp[i][c][k+1], dp[i-1][c1][k] + cost[i][c]);
                }
                dp[i][c][k] = min(dp[i][c][k], dp[i-1][c][k] + cost[i][c]);
            }
        }
        for (int k = 1; k <= i; ++k) {
            for (int c = 1; c <= m; ++c) {
                int &c0 = res[i][k][0];
                int &c1 = res[i][k][1];
                if (dp[i][c][k] < dp[i][c0][k]) {
                    c1 = c0;
                    c0 = c;
                } else if (dp[i][c][k] < dp[i][c1][k]) {
                    c1 = c;
                }
            }
        }
    }
    for (int c = 1; c <= m; ++c) {
        ans = min(ans, dp[n][c][K]);
    }
    if (ans >= C_MAX)
        ans = -1;
    cout << ans << '\n';
    return 0;
}
