#include <bits/stdc++.h>
using namespace std;

const int MAX = (int) 1e5, MOD = (int) 1e9 + 7;
long long dp[MAX];

void init()
{
    dp[0] = dp[1] = 1;
    for (long long i = 2; i < MAX; ++i) {
        dp[i] = (2LL * i - 1) * dp[i-1];
        dp[i] %= MOD;
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    init();
    int t, n;
    cin >> t;
    while (t--) {
        cin >> n;
        map<int, int> cnt;
        for (int i = 0; i < n; ++i) {
            int x;
            cin >> x;
            ++cnt[x];
        }
        vector<int> a;
        for (auto &kv: cnt)
            a.push_back(kv.second);
        long long ans = 1;
        for (int i = 0; i < (int) a.size(); ++i) {
            if (a[i] & 1) {
                ans = (ans * a[i]) % MOD;
                ans = (ans * a[i+1]) % MOD;
                --a[i];
                --a[i+1];
            }
            ans = (ans * dp[a[i]/2]) % MOD;
        }
        cout << ans << '\n';
    }

    return 0;
}
