#include <bits/stdc++.h>

using namespace std;

int dp[35][2][100][100];

int calc(int x, int K)
{
    string s = to_string(x);
    int n = s.size();
    memset(dp, 0, sizeof(dp));
    dp[0][0][0][0] = 1;

    for (int i = 0; i < n; ++i) for (int j = 0; j < 2; ++j) for (int k = 0; k < K; ++k) for (int l = 0; l < K; ++l) {
        int lim = j ? 9 : s[i]-'0';
        for (int d = 0; d < lim+1; ++d) {
            dp[i+1][j || d < lim][(d+k)%K][(10*l+d)%K] += dp[i][j][k][l];
        }
    }

    return dp[n][0][0][0] + dp[n][1][0][0];
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int T, a, b, k, an;
    cin >> T;
    for (int t = 1; t <= T; ++t) {
        cin >> a >> b >> k;
        if (k >= 100) {
            an = 0;
        } else {
            an = calc(b, k) - calc(a-1, k);
        }
        cout << "Case " << t << ": " << an << '\n';
    }
    return 0;
}
