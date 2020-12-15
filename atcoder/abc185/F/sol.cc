#include <bits/stdc++.h>

using namespace std;
using ll = long long;

struct segtree {
    int n;
    vector<int> tree;

    segtree(const vector<int> &a) {
        n = 1;
        while (n < (int)a.size()) n *= 2;
        tree.resize(2*n);
        build(a, 0, 0, n);
    }

    void build(const vector<int> &a, int x, int lx, int rx) {
        if (lx+1 == rx) {
            if (lx < (int)a.size()) {
                tree[x] = a[lx];
            }
            return;
        }

        int m = (lx+rx)/2;
        build(a, 2*x+1, lx, m);
        build(a, 2*x+2, m, rx);
        tree[x] = tree[2*x+1] ^ tree[2*x+2];
    }

    void update(int i, int v, int x, int lx, int rx) {
        if (lx+1 == rx) {
            tree[x] ^= v;
            return;
        }
        int m = (lx+rx)/2;
        if (i < m) {
            update(i, v, 2*x+1, lx, m);
        } else {
            update(i, v, 2*x+2, m, rx);
        }
        tree[x] = tree[2*x+1] ^ tree[2*x+2];
    }

    void update(int i, int v) {
        return update(i, v, 0, 0, n);
    }

    int query(int l, int r, int x, int lx, int rx) {
        if (r <= lx || rx <= l) return 0;
        if (l <= lx && rx <= r) return tree[x];
        int m = (lx+rx)/2;
        return query(l, r, 2*x+1, lx, m) ^ query(l, r, 2*x+2, m, rx);
    }

    int query(int l, int r) {
        return query(l, r, 0, 0, n);
    }
};

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, q;
    cin >> n >> q;
    vector<int> a(n);
    for (auto &it: a) cin >> it;

    segtree st(a);
    while (q--) {
        int t, x, y;
        cin >> t >> x >> y;
        --x;
        if (t == 1) {
            st.update(x, y);
        } else {
            cout << st.query(x, y) << '\n';
        }
    }
    return 0;
}
