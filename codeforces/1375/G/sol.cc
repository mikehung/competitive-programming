#include <bits/stdc++.h>

using namespace std;

vector<vector<int>> g;
vector<int> colors;

void dfs(int color, int u)
{
    colors[u] = color;
    for (int v: g[u]) if (colors[v] == -1) {
        dfs(1-color, v);
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;

    g = vector<vector<int>>(n);
    colors = vector<int>(n, -1);

    for (int i = 0; i < n-1; ++i) {
        int u, v;
        cin >> u >> v;
        --u, --v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    dfs(0, 0);

    int cnt = count(colors.begin(), colors.end(), 0);
    cout << min(cnt, n-cnt)-1 << '\n';
    return 0;
}
