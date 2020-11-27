#include <bits/stdc++.h>

using namespace std;
using ll = long long;

const bool MULTI_TESTCASES = 1;

ll n;
map<int, vector<int>> g;
vector<pair<int, int>> edges;
vector<int> visit, nodes;
set<int> cycle;

struct dsu {
    vector<int> p, sz;

    dsu(int n) {
        p.resize(n);
        sz.assign(n, 1);
        iota(p.begin(), p.end(), 0);
    }

    int find(int u) {
        if (u != p[u]) {
            p[u] = find(p[u]);
        }
        return p[u];
    }

    void merge(int u, int v) {
        u = find(u), v = find(v);
        if (u != v) {
            if (sz[u] < sz[v]) swap(u, v);
            p[v] = u;
            sz[u] += sz[v];
        }
    }

    int size(int u) {
        return sz[find(u)];
    }
};

void dfs(int u, int p)
{
    visit[u] = 1;
    nodes.push_back(u);
    for (auto v: g[u]) if (v != p) {
        if (visit[v] == 0) {
            dfs(v, u);
        } else if (visit[v] == 1) {
            // u, v forms a cycle
            for (int i = nodes.size()-1; nodes[i] != v; --i) {
                cycle.insert(nodes[i]);
            }
            cycle.insert(v);
        }
    }
    visit[u] = 2;
    nodes.pop_back();
}

void solve()
{
    cin >> n;
    g.clear();
    edges.clear();
    visit.assign(n, 0);
    nodes.clear();
    cycle.clear();

    for (int i = 0; i < n; ++i) {
        int u, v;
        cin >> u >> v;
        --u, --v;
        edges.push_back({u, v});
        g[u].push_back(v);
        g[v].push_back(u);
    }

    dfs(0, 0);
    dsu d(n);
    for (auto &edge: edges) if (!cycle.count(edge.first) || !cycle.count(edge.second)) {
        d.merge(edge.first, edge.second);
    }

    ll an = n * (n-1);
    for (auto u: cycle) {
        ll sz = d.size(u);
        an -= sz * (sz-1) / 2;
    }
    cout << an << '\n';
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int testcases = 1;
    if (MULTI_TESTCASES) cin >> testcases;
    while (testcases--) solve();
    return 0;
}
