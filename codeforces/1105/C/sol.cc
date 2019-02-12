#include <bits/stdc++.h>

using namespace std;

const int MOD = 1e9+7;
int n, l, r, cnt[3];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> l >> r;
    --l;
    for (int i = 0; i < 3; ++i) {
        cnt[i] += r / 3;
        cnt[i] -= l / 3;
    }
    for (int i = 1; i <= r%3; ++i) {
        cnt[i]++;
    }
    for (int i = 1; i <= l%3; ++i) {
        cnt[i]--;
    }
    // cerr << cnt[0] << ' ' << cnt[1] << ' ' << cnt[2] << '\n';
    vector<long long> dp(3);
    dp[0] = 1;
    for (int i = 0; i < n; ++i) {
        vector<long long> newdp(3);
        for (int j = 0; j < 3; ++j) for (int k = 0; k < 3; ++k) {
            newdp[(k+j)%3] += (cnt[j] * dp[k]) % MOD;
            newdp[(k+j)%3] %= MOD;
        }
        swap(dp, newdp);
        // cerr << "dp: " << dp[0] << ' ' << dp[1] << ' ' << dp[2] << '\n';
    }
    cout << dp[0] << '\n';

    return 0;
}
