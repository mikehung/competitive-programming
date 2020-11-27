#include <bits/stdc++.h>

using namespace std;
using ll = long long;

struct dsu {
    vector<int> parent, size, color;
    vector<pair<int*, int>> history;

    dsu(int n) {
        parent.resize(n);
        size.resize(n, 1);
        color.resize(n);
        iota(parent.begin(), parent.end(), 0);
    }

    pair<int, int> find(int u) {
        int pu = u, cu = 0;
        while (pu != parent[u]) {
            cu ^= color[pu];
            pu = parent[pu];
        }
        return make_pair(pu, cu);
    }

    bool unite(int u, int v, bool record=false) {
        auto [pu, cu] = find(u);
        auto [pv, cv] = find(v);
        if (pu == pv) {
            return cu != cv;
        } else {
            if (size[pu] < size[pv]) {
                swap(pu, pv);
                swap(cu, cv);
            }

            if (record) history.push_back({&parent[pv], parent[pv]});
            parent[pv] = pu;
            if (record) history.push_back({&color[pv], color[pv]});
            color[pv] = cv ^ cu ^ 1;
            if (record) history.push_back({&size[pu], size[pu]});
            size[pu] += size[pv];
        }
        return true;
    }

    void undo() {
        while (history.size()) {
            *history.back().first = history.back().second;
            history.pop_back();
        }
    }
};

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, m, k;
    cin >> n >> m >> k;
    vector<int> c(n);
    for (int i = 0; i < n; ++i) {
        cin >> c[i];
        --c[i];
    }

    vector<bool> good(k, true);
    vector<pair<pair<int, int>, pair<int, int>>> todo;
    dsu d(n);
    for (int i = 0; i < m; ++i) {
        int u, v;
        cin >> u >> v;
        --u, --v;
        if (c[u] == c[v]) {
            if (!d.unite(u, v)) {
                good[c[u]] = false;
            }
        } else {
            if (c[u] > c[v]) swap(u, v);
            todo.push_back({{c[u], c[v]}, {u, v}});
        }
    }

    sort(todo.begin(), todo.end());
    ll cnt = accumulate(good.begin(), good.end(), 0);
    ll an = cnt * (cnt-1) / 2;
    int i = 0;
    while (i < todo.size()) {
        if (!good[todo[i].first.first] || !good[todo[i].first.second]) {
            ++i;
            continue;
        }
        bool ok = true;
        int j = i;
        while (j < todo.size() && todo[j].first == todo[i].first) {
            if (!d.unite(todo[j].second.first, todo[j].second.second, true)) {
                ok = false;
            }
            ++j;
        }
        d.undo();
        if (!ok) --an;
        i = j;
    }
    cout << an << '\n';

    return 0;
}
