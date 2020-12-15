#include <bits/stdc++.h>

using namespace std;
using ll = long long;

struct dsu {
    int n;
    vector<int> p, r;
    vector<map<int, int>> classes;

    dsu(const vector<int> &c) {
        n = c.size();
        p.resize(n);
        iota(p.begin(), p.end(), 0);
        r.assign(n, 1);
        classes.resize(n);

        for (int i = 0; i < n; ++i) {
            classes[i] = {{c[i], 1}};
        }
    }

    int find(int x) {
        if (x != p[x]) {
            p[x] = find(p[x]);
        }
        return p[x];
    }

    void unite(int x, int y) {
        x = find(x), y = find(y);
        if (x != y) {
            if (r[x] < r[y]) swap(x, y);
            p[y] = p[x];
            for (auto &kv: classes[y]) {
                classes[x][kv.first] += kv.second;
            }
            if (r[x] == r[y]) ++r[x];
        }
    }
};

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, q;
    cin >> n >> q;
    vector<int> c(n);
    for (int i = 0; i < n; ++i) {
        cin >> c[i];
        --c[i];
    }

    dsu d(c);
    while (q--) {
        int op, x, y;
        cin >> op >> x >> y;
        --x, --y;
        if (op == 1) {
            d.unite(x, y);
        } else {
            x = d.find(x);
            if (d.classes[x].count(y)) {
                cout << d.classes[x][y] << '\n';
            } else {
                cout << 0 << '\n';
            }
        }
    }
    return 0;
}
