#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int n, m, logn, t;
map<int, map<int, int>> g;
vector<int> depth, tin, tout;
vector<vector<int>> mins, up;

void dfs(int u, int p)
{
    depth[u] = depth[p]+1;
    tin[u] = t++;

    mins[u][0] = g[u][p];
    up[u][0] = p;

    for (int i = 1; i <= logn; ++i) {
        mins[u][i] = min(mins[u][i-1], mins[up[u][i-1]][i-1]);
        up[u][i] = up[up[u][i-1]][i-1];
    }

    for (auto &kv: g[u]) if (kv.first != p) {
        dfs(kv.first, u);
    }
    tout[u] = t++;
}

bool is_ancestor(int u, int v)
{
    return tin[u] <= tin[v] && tout[v] <= tout[u];
}

int lca(int u, int v)
{
    if (is_ancestor(u, v)) return u;
    if (is_ancestor(v, u)) return v;

    for (int i = logn; i >= 0; --i) {
        if (!is_ancestor(up[u][i], v)) {
            u = up[u][i];
        }
    }
    return up[u][0];
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> n >> m;
    assert(n-1 == m);

    for (int i = 0; i < m; ++i) {
        int u, v, w;
        cin >> u >> v >> w;
        --u, --v;
        g[u][v] = w;
        g[v][u] = w;
    }

    logn = ceil(log2(n));
    depth.resize(n);
    tin.resize(n);
    tout.resize(n);
    mins = vector<vector<int>> (n, vector<int>(logn));
    up = vector<vector<int>> (n, vector<int>(logn));
    dfs(0, 0);

    int q;
    cin >> q;
    while (q--) {
        int u, v, z;
        cin >> u >> v;
        --u, --v;
        z = lca(u, v);
        int an = INT_MAX, d;

        d = depth[u] - depth[z];
        for (int i = 0; i <= logn; ++i) {
            if (d & (1<<i)) {
                an = min(an, mins[u][i]);
                u = up[u][i];
            }
        }

        d = depth[v] - depth[z];
        for (int i = 0; i <= logn; ++i) {
            if (d & (1<<i)) {
                an = min(an, mins[v][i]);
                v = up[v][i];
            }
        }
        cout << an << '\n';
    }
    return 0;
}
