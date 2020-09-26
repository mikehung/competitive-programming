#include <bits/stdc++.h>

using namespace std;
using ll = long long;

ll n, s;
map<ll, map<ll, ll>> g;
vector<ll> weights, costs, counts;
vector<vector<ll>> S;

void dfs(ll u, ll p, ll e_u)
{
    for (auto &[v, e_v]: g[u]) if (v != p) {
        dfs(v, u, e_v);
        if (e_u != -1) counts[e_u] += counts[e_v];
    }

    if (e_u != -1 && counts[e_u] == 0) {
        counts[e_u] = 1;
    }
}

ll saving(int i)
{
    return (weights[i]-weights[i]/2) * counts[i];
}

void solve(int C)
{
    ll sum = 0;
    priority_queue<pair<ll, ll>> qu;
    for (int i = 0; i < n-1; ++i) {
        if (costs[i] == C) {
            sum += weights[i] * counts[i];
            qu.push({saving(i), i});
        }
    }

    while (sum) {
        S[C-1].push_back(sum);

        auto [save, i] = qu.top();
        qu.pop();
        sum -= weights[i] * counts[i];
        weights[i] /= 2;
        sum += weights[i] * counts[i];
        if (weights[i] > 0) qu.push({saving(i), i});
    }
    S[C-1].push_back(0);
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int tt;
    cin >> tt;
    while (tt--) {
        cin >> n >> s;

        g.clear();
        weights.assign(n, 0);
        costs.assign(n, 0);
        counts.assign(n, 0);

        for (int i = 0; i < n-1; ++i) {
            ll u, v;
            cin >> u >> v >> weights[i] >> costs[i];
            --u, --v;
            g[u][v] = i;
            g[v][u] = i;
        }
        dfs(0, 0, -1);

        S.assign(2, {});
        solve(1);
        solve(2);

        int i = 0, j = S[1].size()-1, an = INT_MAX;
        while (S[0][i] > s) ++i;
        for (; i < S[0].size(); ++i) {
            while (j > 0 && S[0][i]+S[1][j-1] <= s) --j;
            an = min(an, i+2*j);
        }
        cout << an << '\n';
    }
    return 0;
}
