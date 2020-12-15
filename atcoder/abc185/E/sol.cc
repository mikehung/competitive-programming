#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, m;
    cin >> n >> m;
    vector<ll> a(n), b(m);
    for (auto &it: a) cin >> it;
    for (auto &it: b) cin >> it;

    vector<vector<ll>> dp(n+1, vector<ll>(m+1));
    for (int i = 0; i <= n; ++i) dp[i][0] = i;
    for (int j = 0; j <= m; ++j) dp[0][j] = j;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (a[i] == b[j]) {
                dp[i+1][j+1] = dp[i][j];
            } else {
                dp[i+1][j+1] = min({dp[i][j+1]+1, dp[i+1][j]+1, dp[i][j]+1});
            }
        }
    }
    cout << dp[n][m] << '\n';
    return 0;
}
