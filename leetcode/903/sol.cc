#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int numPermsDISequence(string s) {
        const int MOD = 1e9 + 7;
        int n = s.size();
        vector<vector<long long>> dp(n+1, vector<long long>(n+1));
        for (int i = 0; i < n+1; ++i) {
            dp[0][i] = 1;
        }
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n-i+1; ++j) {
                int lo, hi;
                if (s[i] == 'D') {
                    lo = 0, hi = j;
                } else {
                    lo = j, hi = n-i;
                }
                for (int nj = lo; nj < hi; ++nj) {
                    dp[i+1][nj] = (dp[i+1][nj] + dp[i][j]) % MOD;
                }
            }
        }
        return dp[n][0];
    }
};

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    string DI = "DID";
    cout << Solution().numPermsDISequence(DI) << '\n';

    return 0;
}
