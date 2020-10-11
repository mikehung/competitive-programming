#include <bits/stdc++.h>

using namespace std;
using ll = long long;

const int N = (int) 1e9;
int n, q, t;
map<int, vector<int>> g;
vector<int> tin, tout, a;

void dfs(int u, int p)
{
    tin[u] = t;
    for (auto v: g[u]) if (v != p) {
        ++t;
        dfs(v, u);
    }
    tout[u] = t;
}

struct segtree {
    int size;
    vector<double> tree;

    segtree(int n) {
        size = 1;
        while (size < n) size *= 2;
        tree.resize(2*size);
    }

    void set(int i, int v, int x, int lx, int rx) {
        if (lx+1 == rx) {
            tree[x] = log(v);
            return;
        }
        int m = (lx+rx)/2;
        if (i < m) {
            set(i, v, 2*x+1, lx, m);
        } else {
            set(i, v, 2*x+2, m, rx);
        }
        tree[x] = tree[2*x+1] + tree[2*x+2];
    }

    void set(int i, int v) {
        set(i, v, 0, 0, size);
    }

    double query(int l, int r, int x, int lx, int rx) {
        if (r <= lx || rx <= l) return 0;
        if (l <= lx && rx <= r) return tree[x];
        int m = (lx+rx)/2;
        return query(l, r, 2*x+1, lx, m) + query(l, r, 2*x+2, m, rx);
    }

    double query(int l, int r) {
        return query(l, r, 0, 0, size);
    }
};

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n;
    for (int i = 0; i < n-1; ++i) {
        int u, v;
        cin >> u >> v;
        --u, --v;
        g[u].push_back(v);
        g[v].push_back(u);
    }

    tin.resize(n);
    tout.resize(n);
    dfs(0, 0);

    segtree st(n);
    for (int i = 0; i < n; ++i) {
        st.set(i, 1);
    }

    cout << fixed << setprecision(12);
    cin >> q;
    while (q--) {
        int tt, x, y;
        cin >> tt >> x >> y;
        if (tt == 1) {
            --x;
            st.set(tin[x], y);
        } else {
            --x, --y;
            double a = st.query(tin[x], tout[x]+1);
            double b = st.query(tin[y], tout[y]+1);
            cout << (a-b >= log(N) ? N : (double)exp(a-b)) << '\n';
        }
    }
    return 0;
}
