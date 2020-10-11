#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int n, q, logn, t;
map<int, vector<int>> g;
vector<int> tin, tout, depth;
vector<vector<int>> lift;

void dfs(int u, int p)
{
    tin[u] = t++;
    depth[u] = depth[p]+1;
    lift[u][0] = p;
    for (int i = 1; i <= logn; ++i) {
        lift[u][i] = lift[lift[u][i-1]][i-1];
    }

    for (auto v: g[u]) if (v != p) {
        dfs(v, u);
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
        if (!is_ancestor(lift[u][i], v)) {
            u = lift[u][i];
        }
    }
    return lift[u][0];
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> n;

    tin.resize(n);
    tout.resize(n);
    depth.resize(n);
    logn = ceil(log2(n));
    lift = vector<vector<int>> (n, vector<int>(logn+1));

    for (int i = 0; i < n-1; ++i) {
        int u, v;
        cin >> u >> v;
        --u, --v;
        g[u].push_back(v);
        g[v].push_back(u);
    }

    dfs(0, 0);

    cin >> q;
    while (q--) {
        int u, v, w, c;
        cin >> u >> v >> c;
        --u, --v;
        w = lca(u, v);
        int c1 = depth[u] - depth[w], c2 = depth[v] - depth[w];
        if (c1+c2 <= c) {
            cout << v+1 << '\n';
        } else {
            int an, sz;
            if (c1 > c) {
                // lift c from u
                an = u, sz = c;
            } else {
                // lift c1+c2-c from v
                an = v, sz = c1+c2-c;
            }
            for (int i = 0; i <= logn; ++i) {
                if (sz & (1<<i)) {
                    an = lift[an][i];
                }
            }
            cout << an+1 << '\n';
        }
    }
    return 0;
}
