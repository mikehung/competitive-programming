#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int n, m;
vector<string> vs;
vector<int> v;

bool check(int u, int v) {
    for (int i = 0; i < n-1; ++i) {
        int cnt = __builtin_popcount((u>>i) & 3) + __builtin_popcount((v>>i) & 3);
        if (cnt % 2 == 0) return false;
    }
    return true;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> m;
    vs.resize(n);
    for (auto &it: vs) cin >> it;

    if (n == 1) {
        cout << 0 << '\n';
    } else if (n > 3) {
        cout << -1 << '\n';
    } else {
        v.resize(m);
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (vs[j][i] == '1') {
                    v[i] += (1<<j);
                }
            }
        }

        vector<int> dp(1<<n);
        for (int i = 0; i < m; ++i) {
            vector<int> ndp(1<<n, 1e9);
            for (int j = 0; j < (1<<n); ++j) {
                for (int k = 0; k < (1<<n); ++k) {
                    if (check(j, k)) {
                        ndp[j] = min(ndp[j], dp[k] + __builtin_popcount(j^v[i]));
                    }
                }
            }
            dp = ndp;
        }
        cout << *min_element(dp.begin(), dp.end()) << '\n';
    }
    return 0;
}
