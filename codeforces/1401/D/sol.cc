#include <bits/stdc++.h>

using namespace std;
using ll = long long;

const int MOD = (int) 1e9+7;
ll n, m;
vector<ll> facs, vals;
map<int, vector<int>> g;

ll dfs(int u, int p) {
    ll an = 0;
    for (auto v: g[u]) if (v != p) {
        int cur = dfs(v, u);
        vals.push_back((n-cur)*cur);
        an += cur;
    }
    return an+1;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--) {
        g.clear();
        vals.clear();
        facs.clear();
        cin >> n;
        for (int i = 0; i < n-1; ++i) {
            int u, v;
            cin >> u >> v;
            --u, --v;
            g[u].push_back(v);
            g[v].push_back(u);
        }
        dfs(0, -1);
        assert((int)vals.size() == n-1);

        cin >> m;
        facs.resize(m);
        for (int i = 0; i < m; ++i) {
            cin >> facs[i];
        }
        while (facs.size() < vals.size()) {
            facs.push_back(1);
        }
        sort(vals.begin(), vals.end());
        sort(facs.begin(), facs.end());

        for (int i = 0; i < facs.size(); ++i) {
            int j = (i < vals.size() ? i : vals.size()-1);
            vals[j] = (vals[j] * facs[i]) % MOD;
        }
        ll an = 0;
        for (int i = 0; i < vals.size(); ++i) {
            an = (an + vals[i]) % MOD;
        }
        cout << an << '\n';
    }
    return 0;
}
