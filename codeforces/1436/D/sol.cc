#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using T = pair<ll, ll>;

int n;
ll an;
vector<ll> a, kids, vals;
map<int, vector<int>> g;

void update(ll u, ll v, ll x)
{
    a[u] -= x;
    a[v] += x;
    vals[v] += x;
}

void dfs2(int u, int p)
{
    if (g[u].empty()) {
        an = max(an, a[u]);
        return;
    }

    ll mx = 0, all_kids = 0;
    for (int v: g[u]) {
        mx = max(mx, vals[v]/kids[v]);
        all_kids += kids[v];
    }

    for (int v: g[u]) {
        ll x = min(a[u], mx * kids[v] - vals[v]);
        if (x > 0) {
            update(u, v, x);
        }
    }

    if (a[u]) {
        mx++;
        for (int v: g[u]) {
            ll x = min(a[u], mx * kids[v] - vals[v]);
            if (x > 0) {
                update(u, v, x);
            }
        }
    }
    assert(a[u] >= 0);

    if (a[u]) {
        ll x = a[u] / all_kids;
        ll left = a[u] % all_kids;
        for (int v: g[u]) {
            ll y = min(left, kids[v]);
            left -= y;
            update(u, v, kids[v]*x+y);
        }
    }
    // assert(a[u] == 0);

    for (int v: g[u]) {
        dfs2(v, u);
    }
}

void dfs(int u, int p)
{
    vals[u] = a[u];
    if (g[u].empty()) {
        kids[u] = 1;
        return;
    }

    for (int v: g[u]) {
        dfs(v, u);
        kids[u] += kids[v];
        vals[u] += vals[v];
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n;
    for (int i = 1; i < n; ++i) {
        int x;
        cin >> x;
        --x;
        g[x].push_back(i);
    }

    a.resize(n);
    kids.resize(n);
    vals.resize(n);
    for (auto &it: a) cin >> it;

    dfs(0, 0);
    // cerr << "vals: "; for (auto x: vals) cerr << x << ' '; cerr << endl;
    // cerr << "kids: "; for (auto x: kids) cerr << x << ' '; cerr << endl;
    dfs2(0, 0);
    // cerr << "a: "; for (auto x: a) cerr << x << ' '; cerr << endl;
    cout << an << '\n';
    return 0;
}
