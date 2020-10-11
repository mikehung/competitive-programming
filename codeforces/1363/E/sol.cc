#include <bits/stdc++.h>

using namespace std;
using ll = long long;

vector<ll> a, b, c;
vector<vector<int>> g, cnt;
ll an;

void dfs(int u, int p, ll cost)
{
    a[u] = min(a[u], cost);
    for (int v: g[u]) if (v != p) {
        dfs(v, u, a[u]);
        cnt[u][0] += cnt[v][0];
        cnt[u][1] += cnt[v][1];
    }

    if (b[u] != c[u]) {
        cnt[u][c[u]]++;
    }
    int mn = min(cnt[u][0], cnt[u][1]);
    cnt[u][0] -= mn;
    cnt[u][1] -= mn;
    an += 2ll * mn * a[u];
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    a.resize(n);
    b.resize(n);
    c.resize(n);
    g.resize(n);
    cnt.assign(n, vector<int>(2));

    int sum = 0;
    for (int i = 0; i < n; ++i) {
        cin >> a[i] >> b[i] >> c[i];
        sum += b[i];
        sum -= c[i];
    }
    if (sum) {
        cout << -1 << '\n';
        return 0;
    }

    for (int i = 0; i < n-1; ++i) {
        int u, v;
        cin >> u >> v;
        --u, --v;
        g[u].push_back(v);
        g[v].push_back(u);
    }

    dfs(0, 0, 1e9+11);

    cout << an << '\n';

    return 0;
}
