#include <bits/stdc++.h>
using namespace std;

const int MAX = (int) 1e5+100, MOD = (int) 1e9 + 7;
long long dp[MAX];

void init()
{
    dp[1] = dp[2] = 1;
    for (long long i = 3; i < MAX; i += 2) {
        dp[i] = dp[i+1] = (i * dp[i-2]) % MOD;
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, t;
    init();
    cin >> t;
    while (t--) {
        map<int, int> cnt;
        cin >> n;
        for (int i = 0; i < n; ++i) {
            int x;
            cin >> x;
            ++cnt[x];
        }
        long long ans = 1;
        for (auto &kv: cnt) {
            cerr << dp[kv.second] << ' ';
            ans = (ans * dp[kv.second]) % MOD;
        }
        cerr << '\n';
        cout << ans << '\n';
    }

    return 0;
}
