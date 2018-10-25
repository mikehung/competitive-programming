#include <bits/stdc++.h>

using namespace std;

const int MAX = 10012;
int n, best, node;
int visit[MAX];
vector<int> G[MAX];

void dfs(int u, int p, int level)
{
    if (visit[u]) return;
    visit[u] = true;
    if (level > best) {
        best = level;
        node = u;
    }
    for (auto &v: G[u]) {
        if (v != p)
            dfs(v, u, level+1);
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n;
    for (int i = 1; i < n; ++i) {
        int u, v;
        cin >> u >> v;
        G[u].push_back(v);
        G[v].push_back(u);
    }
    dfs(1, -1, 0);
    for (int i = 0; i < MAX; ++i)
        visit[i] = 0;
    dfs(node, -1, 0);
    cout << best << '\n';
    return 0;
}
