#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int n, a, b, da, db;
map<int, vector<int>> g;

int distance(int u, int v)
{
    vector<int> d(n, -1);
    queue<int> qu;
    qu.push(u);
    d[u] = 0;
    while (qu.size()) {
        u = qu.front();
        qu.pop();
        if (u == v) return d[u];
        for (auto w: g[u]) if (d[w] == -1) {
            d[w] = d[u]+1;
            qu.push(w);
        }
    }
    return 0;
}

int node, depth;

void dfs(int u, int p, int dep)
{
    if (dep > depth) {
        node = u;
        depth = dep;
    }
    for (auto v: g[u]) if (v != p) {
        dfs(v, u, dep+1);
    }
}

int diameter()
{
    int node1, node2;

    depth = 0;
    dfs(0, -1, 0);
    node1 = node;

    depth = 0;
    dfs(node1, -1, 0);
    node2 = node;

    return distance(node1, node2);
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--) {
        g.clear();

        cin >> n >> a >> b >> da >> db;
        --a, --b;
        for (int i = 0; i < n-1; ++i) {
            int u, v;
            cin >> u >> v;
            --u, --v;
            g[u].push_back(v);
            g[v].push_back(u);
        }

        int dis = distance(a, b);

        if (dis <= da) {
            cout << "Alice\n";
            continue;
        }

        dis = diameter();
        dis = min(dis, db);
        if (da >= (dis+1)/2) {
            cout << "Alice\n";
        } else {
            cout << "Bob\n";
        }
    }
    return 0;
}
