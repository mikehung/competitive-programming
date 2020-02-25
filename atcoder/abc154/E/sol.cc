#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    string s;
    int K;
    cin >> s >> K;
    int n = s.size();
    int dp[n+1][2][K+5];
    memset(dp, 0, sizeof(dp));
    dp[0][0][0] = 1;

    for (int i = 0; i < n; ++i) for (int j = 0; j < 2; ++j) for (int k = 0; k < K+1; ++k) {
        int lim = j ? 9 : s[i]-'0';
        for (int d = 0; d < lim+1; ++d) {
            dp[i+1][j || d < lim][k + (d != 0)] += dp[i][j][k];
        }
    }
    cout << dp[n][0][K] + dp[n][1][K] << '\n';

    return 0;
}
