#include <bits/stdc++.h>

using namespace std;

const int MAX = (int) 3e5 + 12, MOD = 998244353;
long long t, n, m, u, v, ans, all, one;
bool ok;
map<int, vector<int>> g;
vector<int> visit;
vector<long long> pw2;

void dfs(int u, int c)
{
    if (visit[u]) return;
    ++all;
    if (c == 1) ++one;
    visit[u] = c;
    for (int v: g[u]) {
        if (!visit[v]) dfs(v, 3-c);
        else if (visit[v] == visit[u]) {
            ok = false;
            return;
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    pw2.push_back(1);
    for (int i = 0; i < MAX / 2; ++i) {
        long long x = pw2.back() * 2;
        pw2.push_back(x % MOD);
    }
    cin >> t;
    while (t--) {
        g.clear();
        visit.clear();
        ans = 1;
        cin >> n >> m;
        visit.resize(n);
        while (m--) {
            cin >> u >> v;
            --u, --v;
            g[u].push_back(v);
            g[v].push_back(u);
        }
        for (int i = 0; i < n; ++i) if (!visit[i]) {
            ok = true;
            all = one = 0;
            dfs(i, 1);
            if (!ok) {
                ans = 0;
                break;
            }
            ans *= (pw2[one] + pw2[all-one]) % MOD;
            ans %= MOD;
        }
        cout << ans << '\n';
    }
    return 0;
}
