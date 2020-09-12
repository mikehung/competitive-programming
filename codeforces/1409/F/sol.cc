#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    const int N = 205;
    int n, k;
    string s, t;
    cin >> n >> k >> s >> t;
    if (t[0] == t[1]) {
        int cnt = count(s.begin(), s.end(), t[0]);
        cnt = min(cnt+k, n);
        cout << cnt*(cnt-1)/2 << '\n';
        return 0;
    }

    vector<vector<vector<int>>> dp(N, vector<vector<int>>(N, vector<int>(N, -1)));
    dp[0][0][0] = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j <= k; ++j) {
            for (int l = 0; l <= n; ++l) if (dp[i][j][l] != -1) {
                // unchange s[i]
                dp[i+1][j][l] = max(dp[i+1][j][l], dp[i][j][l]);

                int used;
                // set s[i] to t[0]
                used = int(s[i] != t[0]);
                dp[i+1][j+used][l+1] = max(dp[i+1][j+used][l+1], dp[i][j][l]);

                // set s[i] to t[1]
                used = int(s[i] != t[1]);
                dp[i+1][j+used][l] = max(dp[i+1][j+used][l], dp[i][j][l]+l);
            }
        }
    }

    int an = 0;
    for (int i = 0; i <= n; ++i) for (int j = 0; j <= k; ++j) for (int l = 0; l <= n; ++l) {
        an = max(an, dp[i][j][l]);
    }

    cout << an << '\n';

    return 0;
}
