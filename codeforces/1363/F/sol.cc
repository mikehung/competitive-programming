#include <bits/stdc++.h>

using namespace std;

const int M = 26;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int tt;
    cin >> tt;
    while (tt--) {
        int n;
        string s, t;
        cin >> n >> s >> t;
        vector<int> cnt_s(M), cnt_t(M);
        for (int i = 0; i < n; ++i) {
            cnt_s[s[i]-'a']++;
            cnt_t[t[i]-'a']++;
        }

        bool ok = true;
        for (int i = 0; i < M; ++i) if (cnt_s[i] != cnt_t[i]) {
            ok = false;
            break;
        }
        if (!ok) {
            cout << -1 << '\n';
            continue;
        }

        vector<vector<int>> dp(n+1, vector<int>(n+1));
        for (int i = 0; i < n; ++i) {
            vector<int> cnt_s1 = cnt_s;
            vector<int> cnt_t1 = cnt_t;
            int missing = 0;
            for (int i = 0; i < M; ++i) if (cnt_s1[i] < cnt_t1[i]) {
                missing++;
            }

            for (int j = 0; j < n; ++j) {
                dp[i+1][j+1] = dp[i][j+1];
                if (s[i] == t[j]) {
                    dp[i+1][j+1] = dp[i][j] + 1;
                } else if (missing == 0) {
                    dp[i+1][j+1] = max(dp[i+1][j+1], dp[i+1][j]);
                }
                if (--cnt_t1[t[j]-'a'] == cnt_s1[t[j]-'a']) missing--;
            }
            cnt_s[s[i]-'a']--;
        }

        cout << n - dp[n][n] << '\n';
    }
    return 0;
}
