#include <bits/stdc++.h>

using namespace std;

const int MAX = 10005;
int n, dis[MAX];
vector<pair<int, int>> g[MAX];

void dfs(int u)
{
    for (auto &kv: g[u]) {
        int v = kv.first, w = kv.second;
        if (dis[v] == -1) {
            dis[v] = dis[u] + w;
            dfs(v);
        }
    }
}

void solve()
{
    dis[1] = 0;
    dfs(1);
    int mx = 1;
    for (int i = 1; i <= n+1; ++i) {
        if (dis[mx] < dis[i]) mx = i;
    }
    for (int i = 1; i <= n+1; ++i) {
        dis[i] = -1;
    }
    for (int i = 1; i <= n+1; ++i) {
        dis[i] = -1;
    }

    dis[mx] = 0;
    dfs(mx);
    mx = 1;
    for (int i = 1; i <= n+1; ++i) {
        if (dis[mx] < dis[i]) mx = i;
    }
    cout << dis[mx] << '\n';
}

void init()
{
    n = 0;
    for (int i = 0; i < MAX; ++i) {
        g[i].clear();
        dis[i] = -1;
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int u, v, w;
    string line;
    init();
    while (getline(cin, line)) {
        if (line == "") {
            solve();
            init();
        } else {
            ++n;
            istringstream iss(line);
            iss >> u >> v >> w;
            g[u].push_back(make_pair(v, w));
            g[v].push_back(make_pair(u, w));
        }
    }
    solve();
    return 0;
}
