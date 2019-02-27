#include <bits/stdc++.h>

using namespace std;

const int MAX = 1011, MAX2 = MAX*2;
int n, m, par[MAX2], rnk[MAX2], indeg[MAX2], ans[MAX2], rans[MAX], cans[MAX];
set<int> graph[MAX2];
string score[MAX];

int find(int x)
{
    if (x != par[x]) {
        par[x] = find(par[x]);
    }
    return par[x];
}

int merge(int x, int y)
{
    x = find(x), y = find(y);
    if (x != y) {
        if (rnk[x] < rnk[y]) swap(x, y);
        par[y] = x;
        if (rnk[x] == rnk[y]) ++rnk[x];
        return 1;
    }
    return 0;
}

void bye()
{
    cout << "No\n";
    exit(0);
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    for (int i = 0; i < MAX2; ++i) {
        par[i] = i;
        ans[i] = -1;
    }

    cin >> n >> m;
    for (int i = 0; i < n; ++i) {
        cin >> score[i];
    }
    for (int r = 0; r < n; ++r) for (int c = 0; c < m; ++c) {
        if (score[r][c] == '=') {
            merge(r, c+n);
        }
    }
    // build graph & degree
    for (int r = 0; r < n; ++r) for (int c = 0; c < m; ++c) {
        int u = find(r), v = find(c+n);
        if (u == v) {
            if (score[r][c] == '=') continue;
            else bye();
        }
        if (score[r][c] == '<') {
            if (!graph[u].count(v)) {
                graph[u].insert(v);
                ++indeg[v];
            }
        } else if (score[r][c] == '>') {
            if (!graph[v].count(u)) {  // bugfix
                graph[v].insert(u);
                ++indeg[u];
            }
        }
    }
    queue<pair<int, int>> q;
    for (int r = 0; r < n; ++r) {  // bugfix, we could not init indeg with -1
        int u = find(r);
        if (indeg[u] == 0) q.push({u, 1});
    }
    for (int c = 0; c < m; ++c) {
        int u = find(c+n);
        if (indeg[u] == 0) q.push({u, 1});
    }
    while (q.size()) {
        auto [u, val] = q.front();
        q.pop();
        if (ans[u] != -1) continue;  // bugfix
        ans[u] = val;
        for (auto v: graph[u]) {
            if (--indeg[v] == 0) {
                q.push({v, val+1});
            }
        }
    }
    for (int r = 0; r < n; ++r) {
        int u = find(r);
        if (ans[u] == -1) bye();
        rans[r] = ans[u];
    }
    for (int c = 0; c < m; ++c) {
        int u = find(c+n);
        if (ans[u] == -1) bye();
        cans[c] = ans[u];
    }
    cout << "Yes\n";
    for (int r = 0; r < n; ++r) {
        cout << rans[r] << ' ';
    }
    cout << endl;
    for (int c = 0; c < m; ++c) {
        cout << cans[c] << ' ';
    }
    cout << endl;

    return 0;
}
