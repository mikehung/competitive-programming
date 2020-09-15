#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int n;
map<int, vector<int>> g;
vector<int> centroids, sz;

void dfs(int u, int p)
{
    bool ok = true;
    sz[u] = 1;
    for (auto v: g[u]) if (v != p) {
        dfs(v, u);
        sz[u] += sz[v];
        if (sz[v] > n/2) ok = false;
    }
    if (n-sz[u] > n/2) ok = false;
    if (ok) centroids.push_back(u);
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--) {
        g.clear();
        centroids.clear();
        sz.clear();

        cin >> n;
        for (int i = 0; i < n-1; ++i) {
            int u, v;
            cin >> u >> v;
            --u, --v;
            g[u].push_back(v);
            g[v].push_back(u);
        }

        sz.resize(n);
        dfs(0, -1);
        if (centroids.size() == 1) {
            int c = centroids[0];
            cout << c+1 << ' ' << g[c][0]+1 << '\n';
            cout << c+1 << ' ' << g[c][0]+1 << '\n';
        } else {
            int c1 = centroids[0], c2 = centroids[1];
            for (auto v: g[c1]) {
                if (v != c2) {
                    cout << c1+1 << ' ' << v+1 << '\n';
                    cout << c2+1 << ' ' << v+1 << '\n';
                    break;
                }
            }
        }
    }
    return 0;
}
