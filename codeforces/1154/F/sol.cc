#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, m, k;
    cin >> n >> m >> k;
    vector<int> a(n), acc(n+1), dp(n+1, INT_MAX);
    vector<pair<int, int>> b(m);
    for (auto &v: a) cin >> v;
    for (auto &v: b) cin >> v.first >> v.second;
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    for (int i = 0; i < n; ++i) acc[i+1] = acc[i] + a[i];

    dp[0] = 0;
    for (int i = 1; i <= k; ++i) {
        dp[i] = min(dp[i], acc[i]);
        for (int j = 0; j < m && b[j].first <= i; ++j) {
            dp[i] = min(dp[i], dp[i - b[j].first] + acc[i] - acc[i - b[j].first + b[j].second]);
        }
    }
    cout << dp[k] << endl;

    return 0;
}
