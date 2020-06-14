#include <bits/stdc++.h>

using namespace std;

vector<int> pos, par, col;
map<int, vector<int>> g;
vector<int> cycle;

bool dfs(int u, int po, int pa)
{
    if (pa == -1) col[u] = 1;
    else col[u] = 1-col[pa];
    par[u] = pa;
    pos[u] = po;
    int mx = -1;
    for (int v: g[u]) if (v != pa) {
        if (pos[v] != -1) {
            mx = max(mx, pos[v]);
        }
    }
    if (mx != -1) {
        while (pos[u] != mx) {
            cycle.push_back(u);
            u = par[u];
        }
        cycle.push_back(u);
        return true;
    }

    for (int v: g[u]) if (v != pa) {
        if (pos[v] == -1) {
            if (dfs(v, po+1, u)) return true;
        }
    }
    return false;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, m, k;
    cin >> n >> m >> k;
    for (int i = 0; i < m; ++i) {
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }

    par = vector<int>(n+1, -1);
    pos = vector<int>(n+1, -1);
    col = vector<int>(n+1, -1);
    for (int i = 1; i <= n; ++i) if (pos[i] == -1) {
        if (dfs(i, 1, -1)) {
            for (auto x: cycle) cerr << x << ' '; cerr << endl;
            if (cycle.size() <= k) {
                cout << 2 << '\n' << cycle.size() << '\n';
                for (auto x: cycle) cout << x << ' '; cout << '\n';
            } else {
                cout << 1 << '\n';
                for (int i = 0; i < cycle.size() && i/2 < (k+1)/2; i += 2) {
                    cout << cycle[i] << ' ';
                }
                cout << '\n';
            }
            return 0;
        }
    }
    vector<int> zero, one;
    for (int i = 1; i <= n; ++i) {
        if (col[i]) one.push_back(i);
        else zero.push_back(i);
    }
    cout << 1 << '\n';
    if (one.size() >= (k+1)/2) {
        for (int i = 0; i < (k+1)/2; ++i) {
            cout << one[i] << ' ';
        }
    } else {
        for (int i = 0; i < (k+1)/2; ++i) {
            cout << zero[i] << ' ';
        }
    }
    cout << endl;

    return 0;
}
