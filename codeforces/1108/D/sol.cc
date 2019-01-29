#include <bits/stdc++.h>

using namespace std;

const int MAX = (int) 2e5+11;
int n, dp[MAX][3], from[MAX][3];
string s, color("RGB");

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> s;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < 3; ++j) {
            int mn = INT_MAX, fr;
            for (int k = 0; k < 3; ++k) if (j != k) {
                if (mn > dp[i][k]) {
                    mn = dp[i][k];
                    fr = k;
                }
            }
            dp[i+1][j] = mn + (color[j] != s[i]);
            from[i+1][j] = fr;
        }
    }
    int idx = 0;
    for (int i = 0; i < 3; ++i) if (dp[n][idx] > dp[n][i]) {
        idx = i;
    }
    int diff = dp[n][idx];
    string res;
    for (int i = n; i; --i) {
        res += color[idx];
        idx = from[i][idx];
    }
    reverse(res.begin(), res.end());
    cout << diff << '\n' << res << '\n';
    return 0;
}
