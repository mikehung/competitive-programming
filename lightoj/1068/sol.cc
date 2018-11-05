#include <bits/stdc++.h>

using namespace std;

const int MAX_LEN = 13, MAX_MOD = 90;  // the sum of digit will not exceed the MAX_MOD
int dp[MAX_LEN][2][MAX_MOD][MAX_MOD];
long long pw[MAX_LEN];

int calc(int n, int k)
{
    string s = to_string(n);
    int len = s.size();
    for (int i = 0; i < MAX_LEN; ++i) for (int j = 0; j < 2; ++j) for (int k = 0; k < MAX_MOD; ++k) for (int l = 0; l < MAX_MOD; ++l)
        dp[i][j][k][l] = 0;

    dp[0][1][0][0] = 1;
    for (int i = 0; i < len; ++i) for (int f = 0; f < 2; ++f) for (int mo_dig = 0; mo_dig < MAX_MOD; ++mo_dig) for (int mo_num = 0; mo_num < MAX_MOD; ++mo_num) {
        if (!dp[i][f][mo_dig][mo_num]) continue;
        for (int dig = 0; dig <= (f ? s[i]-'0' : 9); ++dig) {
            int n_f = f && s[i]-'0' == dig;
            int n_mo_dig = (mo_dig + dig) % k;
            int n_mo_num = (mo_num + dig * pw[len-i-1]) % k;
            dp[i+1][n_f][n_mo_dig][n_mo_num] += dp[i][f][mo_dig][mo_num];
        }
    }

    return dp[len][0][0][0] + dp[len][1][0][0];
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    pw[0] = 1;
    for (int i = 1; i < 13; ++i)
        pw[i] = pw[i-1] * 10;
    int n, a, b, k, ans;
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> a >> b >> k;
        if (k > MAX_MOD)
            ans = 0;
        else
            ans = calc(b, k) - calc(a-1, k);
        cout << "Case " << i << ": " << ans << '\n';
    }
    return 0;
}
