#include <bits/stdc++.h>

using namespace std;
using ll = long long;

map<ll, map<ll, ll>> g;
vector<ll> weights, edges;

void dfs(ll u, ll p)
{
    for (auto &kv: g[u]) if (kv.first != p) {
        dfs(kv.first, u);
        weights[u] += weights[kv.first];
    }

    if (weights[u] == 0) weights[u] = 1;
    edges[u] = g[u][p];
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int tt;
    cin >> tt;
    while (tt--) {
        ll n, s;
        cin >> n >> s;

        g.clear();
        for (int i = 0; i < n-1; ++i) {
            ll u, v, w;
            cin >> u >> v >> w;
            --u, --v;
            g[u][v] = w;
            g[v][u] = w;
        }

        weights.assign(n, 0);
        edges.assign(n, 0);
        dfs(0, 0);

        ll sum = 0;
        priority_queue<pair<ll, pair<ll, ll>>> pq;  // next saving, edge, weight
        for (int i = 1; i < n; ++i) {
            ll e = edges[i], w = weights[i];
            ll cur = e*w;
            ll nxt = (e/2)*w;
            pq.push({cur-nxt, {e, w}});
            sum += cur;
        }

        ll an = 0;
        while (sum > s) {
            ++an;

            auto par = pq.top().second;
            pq.pop();

            ll e = par.first, w = par.second;
            ll cur = e*w;
            ll nxt = (e/2)*w;
            sum -= cur;
            sum += nxt;

            e /= 2;
            cur = e*w;
            nxt = (e/2)*w;
            pq.push({cur-nxt, {e, w}});
        }
        cout << an << '\n';
    }
    return 0;
}
