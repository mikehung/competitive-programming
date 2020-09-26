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
        vector<int> l(n), r(n);
        for (int i = 0; i < n; ++i) {
            cin >> l[i] >> r[i];
            comp[l[i]] = comp[r[i]] = 0;
        }
        int sz = 0;
        for (auto &kv: comp) kv.second = sz++;
        for (int i = 0; i < n; ++i) {
            l[i] = comp[l[i]];
            r[i] = comp[r[i]];
        }
        map<int, vector<int>> end_at;
        for (int i = 0; i < n; ++i) {
            end_at[l[i]].push_back(r[i]);
        }

        vector<vector<int>> dp(sz, vector<int>(sz));
        for (int k = 0; k <= sz; ++k) {
            for (int i = 0, j = i+k; j < sz; ++i, ++j) {
                bool has_ij = false;
                if (i+1 <= j) dp[i][j] = max(dp[i][j], dp[i+1][j]);
                for (int nj: end_at[i]) {
                    if (nj == j) has_ij = true;
                    else if (nj+1 <= j) {
                        dp[i][j] = max(dp[i][j], dp[i][nj]+dp[nj+1][j]);
                    }
                }
                if (has_ij) dp[i][j] += 1;
            }
        }
        cout << dp[0][sz-1] << '\n';
    }
    return 0;
}
