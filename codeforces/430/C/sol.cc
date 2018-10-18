#include <bits/stdc++.h>
using namespace std;

#ifdef DEBUG
    #define dbg(...) fprintf(stderr, __VA_ARGS__)
#else
    #define dbg(...)
#endif

const int MAX = (int) 1e5 + 5;
int n;
vector<int> G[MAX], ans;
bool init[MAX], goal[MAX];

void dfs(int u, int p, vector<bool> flips, int level)
{
    if ((init[u]^flips[level]) != goal[u]) {
        ans.push_back(u);
        flips[level] = 1 - flips[level];
    }
    for (int v : G[u]) {
        if (v == p) continue;
        dfs(v, u, flips, 1-level);
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n;
    int u, v;
    for (int i = 1; i < n; ++i) {
        cin >> u >> v;
        G[u].push_back(v);
        G[v].push_back(u);
    }
    for (int i = 1; i <= n; ++i) {
        cin >> init[i];
    }
    for (int i = 1; i <= n; ++i) {
        cin >> goal[i];
    }
    vector<bool> flips(2);
    dfs(1, -1, flips, 0);
    cout << ans.size() << '\n';
    for (auto x : ans) {
        cout << x << '\n';
    }
    return 0;
}
