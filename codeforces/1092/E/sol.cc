#include <bits/stdc++.h>

using namespace std;

const int MAX = 1005;
int n, m, u, v, group[MAX], visit[MAX], degree[MAX];
vector<int> graph[MAX], centers;
set<int> nodes;

void dfs(int u, int id)
{
    if (group[u]) return;
    nodes.push_back(u);
    group[u] = id;
    for (int v: graph[u]) dfs(v, id);
}

void find_center()
{
    vector<int> rm;
    for (int u: nodes) {
        if (degree[u] == 1) rm.push_back(u);
    }
    while (nodes.size() > 2) {
        vector<int> nrm;
        for (int u: rm) {
            nodes.erase(u);
            for (int v: graph[u]) {
                if (--degree[v] == 1)
                    nrm.push_back(v);
            }
        }
        rm = nrm;
    }
    centers.push_back(*nodes.begin());
}

int diameter()
{
    for (int i = 0; i < n; ++i) visit[i] = 0;
    dfs(0);
    for (int i = 0; i < n; ++i) visit[i] = 0;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> m;
    for (int i = 0; i < m; ++i) {
        cin >> u >> v;
        --u, --v;
        ++degree[u], ++degree[v];
        graph[u].push_back(v);
        graph[v].push_back(u);
    }
    int id = 1;
    for (int i = 0; i < n; ++i) if (!group[i]) {
        nodes.clear();
        dfs(i, id);
        find_center();
        ++id;
    }

    for (int i = 1; i < (int) centers.size(); ++i) {
        u = centers[0], v = centers[i];
        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    cout << diameter();
    if (centers.size()) {
        cout << centers.size() << '\n';
        for (int i = 1; i < (int) centers.size(); ++i) {
            u = centers[0], v = centers[i];
            cout << u << ' ' << v << '\n';
        }
    }

    return 0;
}
