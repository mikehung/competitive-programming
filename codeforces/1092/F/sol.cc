#include <bits/stdc++.h>

using namespace std;

const int MAX = (int) 2e5 + 112;
int n;
bool visit[MAX];
vector<int> g[MAX];
long long ans, all, a[MAX], val[MAX];

void dfs(int p, int u, int d)
{
    if (visit[u]) return;
    visit[u] = 1;
    ans += a[u] * d;
    for (int v: g[u]) dfs(u, v, d+1);
    val[u] += a[u];
    if (p != -1) {
        val[p] += val[u];
    }
}

void dfs2(int u, long long cur)
{
    if (visit[u]) return;
    visit[u] = 1;
    ans = max(ans, cur);
    for (int v: g[u]) {
        dfs2(v, cur + (all - 2 * val[v]));
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        all += a[i];
    }
    for (int i = 0; i < n-1; ++i) {
        int u, v;
        cin >> u >> v;
        --u, --v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    dfs(-1, 0, 0);
    for (int i = 0; i < n; ++i) {
        visit[i] = 0;
    }
    dfs2(0, ans);
    cout << ans << '\n';

    return 0;
}
