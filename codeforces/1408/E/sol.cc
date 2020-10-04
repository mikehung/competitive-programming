#include <bits/stdc++.h>

using namespace std;
using ll = long long;

struct dsu {
    vector<int> p, r;
    dsu(int n) {
        p.resize(n);
        r.resize(n);
        for (int i = 0; i < n; ++i) p[i] = i;
    }

    int find(int u) {
        if (u != p[u]) {
            p[u] = find(p[u]);
        }
        return p[u];
    }

    bool merge(int u, int v) {
        u = find(u), v = find(v);
        if (u != v) {
            if (r[u] < r[v]) swap(u, v);
            p[v] = p[u];
            if (r[u] == r[v]) r[u]++;
            return true;
        }
        return false;
    }
};

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, m;
    cin >> m >> n;
    vector<ll> a(m), b(n);
    for (auto &it: a) cin >> it;
    for (auto &it: b) cin >> it;

    vector<pair<int, pair<int, int>>> edges;
    ll sum = 0, spanning = 0;
    for (int u = 0; u < m; ++u) {
        int cnt;
        cin >> cnt;
        while (cnt--) {
            int v;
            cin >> v;
            --v;
            ll cost = a[u] + b[v];
            sum += cost;
            edges.push_back({cost, {n+u, v}});
        }
    }
    sort(edges.rbegin(), edges.rend());

    dsu d(n+m);
    for (auto &edge: edges) {
        ll cost = edge.first;
        int u = edge.second.first, v = edge.second.second;
        if (d.merge(u, v)) {
            spanning += cost;
        }
    }
    cout << sum - spanning << '\n';
    return 0;
}
