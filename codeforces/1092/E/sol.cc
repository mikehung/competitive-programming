#include <bits/stdc++.h>

using namespace std;

const int MAX = 1005;
int n, m, u, v, group[MAX], visit[MAX], degree[MAX];
vector<int> graph[MAX], centers;
set<int> nodes;
int best, ans;

void dfs(int u, int id)
{
    if (group[u]) return;
    nodes.insert(u);
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

void dfs2(int u, int cur)
{
    if (visit[u]) return;
    visit[u] = 1;
    if (cur > ans) {
        ans = cur;
        best = u;
    }
    for (int v: graph[u]) dfs2(v, cur+1);
}

int diameter(int u=0)
{
    ans = 0;
    for (int i = 0; i < n; ++i) visit[i] = 0;
    dfs2(u, 0);

    ans = 0;
    for (int i = 0; i < n; ++i) visit[i] = 0;
    dfs2(best, 0);

    return ans;
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
    int id = 1, best_d = 0, idx = 0;
    for (int i = 0; i < n; ++i) if (!group[i]) {
        nodes.clear();
        dfs(i, id);
        find_center();
        int d = diameter(i);
        if (d > best_d) {
            best_d = d;
            idx = centers.size() - 1;
        }
        ++id;
    }

    for (int i = 0; i < (int) centers.size(); ++i) {
        if (i == idx) continue;
        u = centers[idx], v = centers[i];
        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    cout << diameter() << '\n';
    if (centers.size()) {
        for (int i = 0; i < (int) centers.size(); ++i) {
            if (i == idx) continue;
            u = centers[idx], v = centers[i];
            cout << u+1 << ' ' << v+1 << '\n';
        }
    }

    return 0;
}
