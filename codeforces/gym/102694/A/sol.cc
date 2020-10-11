#include <bits/stdc++.h>

using namespace std;
using ll = long long;

map<int, vector<int>> g;
vector<int> depth;
int cand, max_depth;

void dfs(int u, int p)
{
    depth[u] = depth[p]+1;
    if (depth[u] > max_depth) {
        max_depth = depth[u];
        cand = u;
    }

    for (auto v: g[u]) if (v != p) {
        dfs(v, u);
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    for (int i = 0; i < n-1; ++i) {
        int u, v;
        cin >> u >> v;
        --u, --v;
        g[u].push_back(v);
        g[v].push_back(u);
    }

    depth.assign(n, 0);
    max_depth = 0;
    dfs(0, 0);

    depth.assign(n, 0);
    max_depth = 0;
    dfs(cand, cand);
    cout << (depth[cand]-1) * 3 << '\n';
    return 0;
}
