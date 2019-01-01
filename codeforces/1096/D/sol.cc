#include <bits/stdc++.h>

using namespace std;

const int MAX = (int) 1e5 + 112;
int n, a[MAX];
string s, t("hard");
long long dp[4][MAX];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> s;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    for (int i = 1; i <= n; ++i) for (int j = 0; j < 4; ++j) {
        dp[j][i] = 1e18;
    }
    for (int i = 0; i < n; ++i) for (int j = 0; j < 4; ++j) {
        if (s[i] == t[j]) {
            // remove
            dp[j][i+1] = min(dp[j][i+1], dp[j][i] + a[i]);
            // keep
            if (j != 3) {
                dp[j+1][i+1] = min(dp[j+1][i+1], dp[j][i]);
            }
        } else {
            dp[j][i+1] = min(dp[j][i+1], dp[j][i]);
        }
    }
    long long ans = 1e18;
    for (int j = 0; j < 4; ++j) {
        ans = min(ans, dp[j][n]);
    }
    cout << ans << '\n';

    return 0;
}
