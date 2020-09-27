#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int tt;
    cin >> tt;
    while (tt--) {
        int n;
        cin >> n;

        map<int, int> comp;
        vector<int> a(n);
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
            comp[a[i]] = 0;
        }

        int m = 0;
        for (auto &kv: comp) kv.second = m++;
        vector<vector<int>> pos(m);
        for (int i = 0; i < n; ++i) {
            a[i] = comp[a[i]];
            pos[a[i]].push_back(i);
        }

        vector<int> dp(m);
        dp[0] = pos[0].size();
        for (int i = 1; i < m; ++i) {
            dp[i] = pos[i].size();
            if (pos[i-1].back() < pos[i].front()) {
                dp[i] += dp[i-1];
            } else {
                dp[i] += lower_bound(pos[i-1].begin(), pos[i-1].end(), pos[i].front()) - pos[i-1].begin();
            }
        }
        for (int i = 0; i < m-1; ++i) {
            int cnt = lower_bound(pos[i+1].begin(), pos[i+1].end(), pos[i].back()) - pos[i+1].begin();
            dp[i] += pos[i+1].size() - cnt;
        }
        int mx = *max_element(dp.begin(), dp.end());
        for (int i = 0; i < m-1; ++i) {
            for (int j = 0; j < pos[i].size(); ++j) {
                int cnt = j+1 + pos[i+1].size() - (lower_bound(pos[i+1].begin(), pos[i+1].end(), pos[i][j]) - pos[i+1].begin());
                mx = max(mx, cnt);
            }
        }
        cout << n-mx << '\n';
    }
    return 0;
}
