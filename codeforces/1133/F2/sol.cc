#include <bits/stdc++.h>

using namespace std;

const int MAX = (int) 2e5+11;
int n, m, D, cnt, u, v, deg[MAX], par[MAX], rnk[MAX], visit[MAX];
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

void dfs(int u)
{
    if (visit[u]) return;
    visit[u] = 1;
    for (auto v: g[u]) dfs(v);
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    for (int i = 0; i < MAX; ++i) par[i] = i;

    vector<pair<int, int>> ans, edge, e1;
    cin >> n >> m >> D;
    for (int i = 0; i < m; ++i) {
        cin >> u >> v;
        --u, --v;
        ++deg[u];
        ++deg[v];
        if (u != 0 && v != 0) {
            g[u].push_back(v);
            g[v].push_back(u);
            edge.push_back({u, v});
        } else {
            if (v == 0) swap(u, v);
            e1.push_back({u, v});
        }
    }

    for (int i = 1; i < n; ++i) if (!visit[i]) {
        ++cnt;
        dfs(i);
    }
    if (cnt > D || D > e1.size()) bye();
    for (int i = 0; i < n; ++i) visit[i] = 0;
    D -= cnt;
    for (auto &par: e1) {
        v = par.second;
        int add = 0;
        if (!visit[v]) {
            add = 1;
            dfs(v);
        } else if (D > 0) {
            add = 1;
            --D;
        }
        if (add) {
            g[v].push_back(0);
            g[0].push_back(v);
            edge.push_back({v, 0});
        }
    }
    for (auto v: g[0]) {
        ans.push_back({0, v});
        merge(0, v);
    }
    for (auto &par: edge) {
        u = par.first, v = par.second;
        if (merge(u, v)) {
            ans.push_back({u, v});
        }
    }

    cout << "YES\n";
    for (auto &par: ans) {
        cout << par.first+1 << ' ' << par.second+1 << endl;
    }
    return 0;
}
