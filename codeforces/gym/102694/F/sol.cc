#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int n, q, t;
vector<int> tin, tout;
map<int, vector<int>> g;

struct segtree {
    int sz;
    vector<ll> tree;

    segtree(int n) {
        sz = 1;
        while (sz < n) sz *= 2;
        tree.resize(2*sz);
    }

    void update(int i, ll v, int x, int lx, int rx) {
        if (lx+1 == rx) {
            tree[x] += v;
            return;
        }
        int m = (lx+rx)/2;
        if (i < m) update(i, v, 2*x+1, lx, m);
        else update(i, v, 2*x+2, m, rx);
        tree[x] = tree[2*x+1] + tree[2*x+2];
    }

    void update(int i, ll v) {
        update(i, v, 0, 0, sz);
    }

    ll query(int l, int r, int x, int lx, int rx) {
        if (r <= lx || rx <= l) return 0;
        if (l <= lx && rx <= r) return tree[x];
        int m = (lx+rx)/2;
        return query(l, r, 2*x+1, lx, m) + query(l, r, 2*x+2, m, rx);
    }

    ll query(int l, int r) {
        return query(l, r, 0, 0, sz);
    }
};

void dfs(int u, int p)
{
    tin[u] = t;
    for (auto v: g[u]) if (v != p) {
        ++t;
        dfs(v, u);
    }
    tout[u] = t;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int tt;
    cin >> tt;
    while (tt--) {
        cin >> n >> q;

        t = 0;
        tin.resize(n);
        tout.resize(n);
        g.clear();
        for (int i = 0; i < n-1; ++i) {
            int u, v;
            cin >> u >> v;
            --u, --v;
            g[u].push_back(v);
            g[v].push_back(u);
        }

        dfs(0, 0);
        segtree st(t);
        while (q--) {
            int a, b, x;
            cin >> a >> b >> x;
            --a, --b;
            if (x == 0) {
                if (tin[a] < tin[b]) swap(a, b);
                cout << abs(st.query(tin[a], tout[a]+1)) << '\n';
            } else {
                st.update(tin[a], x);
                st.update(tin[b], -x);
            }
        }
    }
    return 0;
}
