#include <bits/stdc++.h>

using namespace std;

const int MAX_N = 55;
int n, m, depth[MAX_N], parent[MAX_N];
vector<int> tree[MAX_N];
long long status[25];

void dfs(int p, int u, int d)
{
    if (depth[u] != 0) return;
    depth[u] = d;
    parent[u] = p;
    for (int v: tree[u]) dfs(u, v, d+1);
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n;
    for (int i = 0; i < n-1; ++i) {
        int u, v;
        cin >> u >> v;
        --u, --v;
        tree[u].push_back(v);
        tree[v].push_back(u);
    }
    dfs(-1, 0, 1);

    cin >> m;
    for (int i = 0; i < m; ++i) {
        int u, v;
        cin >> u >> v;
        --u, --v;
        if (depth[u] < depth[v]) swap(u, v);
        while (depth[u] > depth[v]) {
            status[i] |= 1ll<<u;
            u = parent[u];
        }
        while (u != v) {
            status[i] |= 1ll<<u;
            status[i] |= 1ll<<v;
            u = parent[u];
            v = parent[v];
        }
    }

    long long an = 0;
    for (int i = 0; i < 1<<m; ++i) {
        long long all_status = 0;
        int cnt = 0;
        for (int j = 0; j < m; ++j) if ((i>>j) & 1) {
            all_status |= status[j];
            ++cnt;
        }
        int edges = 0;
        for (int j = 0; j < n; ++j) if ((all_status>>j) & 1) {
            edges++;
        }
        long long val = 1ll<<(n-edges-1);
        if (cnt % 2) an -= val;
        else an += val;
    }
    cout << an << endl;

    return 0;
}
