#include <bits/stdc++.h>

using namespace std;

int calc(string &s)
{
    int n = s.size();
    vector<vector<int>> dp(n+1, vector<int>(3));

    for (int i = 0; i < n; ++i) {
        int zero = (s[i]-'0') != 0, one = 1-zero;
        dp[i+1][0] = dp[i][0] + zero; // 00
        dp[i+1][2] = dp[i][1] + zero; // 10
        dp[i+1][2] = min(dp[i+1][2], dp[i][2] + zero); // 010
        dp[i+1][1] = dp[i][0] + one; // 01
        dp[i+1][1] = min(dp[i+1][1], dp[i][1] + one); // 11
    }

    return min(dp[n][0], min(dp[n][1], dp[n][2]));
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--) {
        int n, k;
        string s;
        cin >> n >> k >> s;

        int all = 0;
        vector<string> ss(k);
        for (int i = 0; i < n; ++i) {
            ss[i%k] += s[i];
            if (s[i] == '1') {
                all++;
            }
        }

        int an = all;
        for (auto &str: ss) {
            int base = all - count(str.begin(), str.end(), '1');
            if (base >= an) continue;
            an = min(an, base+calc(str));
        }
        cout << an << '\n';
    }
    return 0;
}
