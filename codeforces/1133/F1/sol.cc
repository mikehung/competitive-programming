#include <bits/stdc++.h>

using namespace std;

const int MAX = (int) 2e5+11;
int n, m, u, v, deg[MAX];
vector<int> g[MAX];
vector<pair<int, int>> ans;

void bfs(int u)
{
    vector<int> visit(n);
    queue<int> q;
    q.push(u);
    visit[u] = 1;
    while (q.size()) {
        u = q.front();
        q.pop();
        for (auto v: g[u]) if (!visit[v]) {
            visit[v] = 1;
            q.push(v);
            ans.push_back({u, v});
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int mx = 0;
    cin >> n >> m;
    for (int i = 0; i < m; ++i) {
        cin >> u >> v;
        --u, --v;
        ++deg[u];
        ++deg[v];
        g[u].push_back(v);
        g[v].push_back(u);
        if (deg[u] > deg[mx]) mx = u;
        if (deg[v] > deg[mx]) mx = v;
    }
    bfs(mx);
    for (auto &par: ans) {
        cout << par.first+1 << ' ' << par.second+1 << endl;
    }

    return 0;
}
