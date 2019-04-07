#include <bits/stdc++.h>

using namespace std;

const long long MOD = 1000000007;

bool check(int p, long long W)
{
    for (int i = 1; i <= W-1; ++i) {
        if (((p >> i) & 1) && ((p >> (i-1)) & 1)) return false;
    }
    return true;
}

void solve(long long H, long long W, long long K)
{
    --W, --K;
    vector<vector<long long>> dp(H+1, vector<long long>(W+1));
    dp[0][0] = 1;
    for (int h = 0; h < H; ++h) for (int w = 0; w <= W; ++w) if (dp[h][w]) {
        for (int p = 0; p < (1<<W); ++p) {
            if (check(p, W)) {
                if (w > 0 && ((p >> (w-1)) & 1)) {
                    (dp[h+1][w-1] += dp[h][w]) %= MOD;
                } else if (w+1 <= W && ((p >> w) & 1)) {
                    (dp[h+1][w+1] += dp[h][w]) %= MOD;
                } else {
                    (dp[h+1][w] += dp[h][w]) %= MOD;
                }
            }
        }
    }
    cout << dp[H][K] << endl;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    long long H, W, K;
    cin >> H >> W >> K;
    solve(H, W, K);
    return 0;
}
