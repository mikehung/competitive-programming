#include <bits/stdc++.h>

using namespace std;

const int MAX = (int) 2e5+11;
int n, m, u, v, deg[MAX], par[MAX], rnk[MAX];
vector<int> g[MAX];

int find(int x)
{
    if (x != par[x])
        par[x] = find(par[x]);
    return par[x];
}

int merge(int x, int y)
{
    x = find(x), y = find(y);
    if (x != y) {
        if (rnk[x] < rnk[y]) swap(x, y);
        par[y] = x;
        if (rnk[x] == rnk[y]) ++rnk[x];
        return 1;
    }
    return 0;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    for (int i = 0; i < MAX; ++i) par[i] = i;

    vector<pair<int, int>> ans, edge;
    int mx = 0;
    cin >> n >> m;
    for (int i = 0; i < m; ++i) {
        cin >> u >> v;
        --u, --v;
        ++deg[u];
        ++deg[v];
        g[u].push_back(v);
        g[v].push_back(u);
        edge.push_back({u, v});
        if (deg[u] > deg[mx]) mx = u;
        if (deg[v] > deg[mx]) mx = v;
    }
    for (auto v: g[mx]) {
        ans.push_back({mx, v});
        merge(mx, v);
    }
    for (auto &par: edge) {
        u = par.first, v = par.second;
        if (merge(u, v)) {
            ans.push_back({u, v});
        }
    }
    for (auto &par: ans) {
        cout << par.first+1 << ' ' << par.second+1 << endl;
    }

    return 0;
}
