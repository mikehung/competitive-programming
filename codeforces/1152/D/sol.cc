#include <bits/stdc++.h>

using namespace std;

const int MAX = 1011, MOD = 1e9+7;
int n;
pair<long long, bool> dp[2*MAX][MAX];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n;

    dp[0][0] = {0, true};
    for (int i = 1; i <= 2*n; ++i) {
        for (int b = 0; b <= min(i, n); ++b) {
            bool free = false;
            long long v = 0;
            if (b != 0) {
                v += dp[i-1][b-1].first;
                v %= MOD;
                free |= dp[i-1][b-1].second;
            }
            if (b != n) {
                v += dp[i-1][b+1].first;
                v %= MOD;
                free |= dp[i-1][b+1].second;
            }
            if (free) {
                v += 1;
                v %= MOD;
            }
            dp[i][b] = {v, !free};
        }
    }
    cout << dp[2*n][0].first << endl;
    return 0;
}
