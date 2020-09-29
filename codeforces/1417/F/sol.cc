#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int n, m, q, t;
vector<int> p, delete_edges, parents, tin, tout, a;
vector<pair<int, int>> edges, queries;
map<int, vector<int>> g;

struct segtree {
    int sz;
    vector<int> tree, pos;
    segtree(const vector<int> &a) {
        sz = 1;
        while (sz < a.size()) sz *= 2;
        tree.resize(2*sz);
        pos.resize(n+1);

        build(a, 0, 0, sz);
    }

    void build(const vector<int> &a, int x, int lx, int rx) {
        if (lx+1 == rx) {
            if (lx < a.size()) {
                int v = a[lx];
                if (v < n) {
                    tree[x] = p[v];
                    pos[tree[x]] = lx;
                }
            }
            return;
        }
        int m = (lx+rx)/2;
        build(a, 2*x+1, lx, m);
        build(a, 2*x+2, m, rx);
        tree[x] = max(tree[2*x+1], tree[2*x+2]);
    }

    int query(int l, int r, int x, int lx, int rx) {
        if (r <= lx || rx <= l) return 0;
        if (l <= lx && rx <= r) return tree[x];
        int m = (lx+rx)/2;
        return max(query(l, r, 2*x+1, lx, m), query(l, r, 2*x+2, m, rx));
    }

    int query(int l, int r) {
        return query(l, r, 0, 0, sz);
    }

    void update(int i, int x, int lx, int rx) {
        if (lx+1 == rx) {
            tree[x] = 0;
            return;
        }
        int m = (lx+rx)/2;
        if (i < m) {
            update(i, 2*x+1, lx, m);
        } else {
            update(i, 2*x+2, m, rx);
        }
        tree[x] = max(tree[2*x+1], tree[2*x+2]);
    }

    void update(int v) {
        update(pos[v], 0, 0, sz);
    }
};

void dfs(int u, int p)
{
    tin[u] = t;
    a.push_back(u);
    for (int v: g[u]) if (v != p) {
        ++t;
        dfs(v, u);
    }
    tout[u] = t;
}

struct dsu {
    vector<int> p;

    dsu(int n) {
        p.resize(n);
        for (int i = 0; i < n; ++i) p[i] = i;
    }

    int find(int u) {
        if (p[u] != u) {
            p[u] = find(p[u]);
        }
        return p[u];
    }

    void merge(int u, int v) {
        u = find(u), v = find(v);
        if (u != v) {
            int w = p.size();
            p.push_back(w);
            p[u] = p[v] = w;
            g[w].push_back(u);
            g[w].push_back(v);
        }
    }
};

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> m >> q;

    p.resize(n);
    delete_edges.resize(m);
    edges.resize(m);
    queries.resize(q);

    for (int i = 0; i < n; ++i) {
        cin >> p[i];
    }

    for (int i = 0; i < m; ++i) {
        cin >> edges[i].first >> edges[i].second;
        edges[i].first--, edges[i].second--;
    }

    for (int i = 0; i < q; ++i) {
        cin >> queries[i].first >> queries[i].second;
        queries[i].second--;
        if (queries[i].first == 2) {
            assert(delete_edges[queries[i].second] == 0);
            delete_edges[queries[i].second] = 1;
        }
    }

    for (int i = 0; i < m; ++i) if (delete_edges[i] == 0) {
        delete_edges[i] = 1;
        queries.push_back({2, i});
    }
    q = queries.size();
    reverse(queries.begin(), queries.end());

    dsu d(n);
    for (auto &[type, x]: queries) {
        if (type == 1) {
            parents.push_back(d.find(x));
        } else {
            int u = edges[x].first, v = edges[x].second;
            d.merge(u, v);
        }
    }
    reverse(queries.begin(), queries.end());
    reverse(parents.begin(), parents.end());

    int sz = d.p.size();
    tin.resize(sz);
    tout.resize(sz);
    for (int i = 0; i < sz; ++i) if (d.p[i] == i) {
        dfs(i, i);
        ++t;
    }

    segtree st(a);
    int idx = 0;
    for (auto &[type, x]: queries) if (type == 1) {
        int p = parents[idx++];
        int an = st.query(tin[p], tout[p]+1);
        if (an != 0) {
            st.update(an);
        }
        cout << an << '\n';
    }
    return 0;
}
