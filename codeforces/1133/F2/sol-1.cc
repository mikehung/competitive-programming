#include <bits/stdc++.h>

using namespace std;

const int MAX = (int) 2e5+11;
int n, m, D, E, u, v, deg[MAX], par[MAX], rnk[MAX];
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

void bye()
{
    cout << "NO\n";
    exit(0);
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    for (int i = 0; i < MAX; ++i) par[i] = i;

    vector<pair<int, int>> ans, edge;
    cin >> n >> m >> D;
    E = n - 1 - D;
    for (int i = 0; i < m; ++i) {
        cin >> u >> v;
        --u, --v;
        ++deg[u];
        ++deg[v];
        g[u].push_back(v);
        g[v].push_back(u);
        edge.push_back({u, v});
    }
    if (deg[0] < D) bye();
    vector<int> one;
    for (auto v: g[0]) {
        if (deg[v] == 1) one.push_back(v);
    }
    if (one.size() > D) bye();
    for (auto v: one) {
        ans.push_back({0, v});
        merge(0, v);
    }
    D -= one.size();
    for (auto &par: edge) {
        if (E == 0) break;
        u = par.first, v = par.second;
        if (u == 0 || v == 0) continue;
        if (merge(u, v)) {
            ans.push_back({u, v});
            --E;
        }
    }
    for (auto v: g[0]) {
        if (D == 0) break;
        if (merge(0, v)) {
            ans.push_back({0, v});
            merge(0, v);
            --D;
        }
    }
    if (D || E || ans.size() != n-1) bye();
    cout << "YES\n";
    for (auto &par: ans) {
        cout << par.first+1 << ' ' << par.second+1 << endl;
    }
    return 0;
}
