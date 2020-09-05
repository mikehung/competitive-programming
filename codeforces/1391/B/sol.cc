#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int n, m;

struct union_find {
    vector<int> parent;
    int groups;

    union_find(int sz) {
        parent = vector<int>(sz);
        iota(parent.begin(), parent.end(), 0);
        groups = sz;
    }

    int find(int x) {
        if (parent[x] != x) {
            parent[x] = find(parent[x]);
        }
        return parent[x];
    }

    void unite(int x, int y) {
        x = find(x), y = find(y);
        if (x != y) {
            groups--;
            parent[x] = parent[y];
        }
    }
};

int idx(int r, int c) {
    return r*m + c;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--) {
        cin >> n >> m;
        union_find uf(n*m);
        for (int i = 0; i < n; ++i) {
            string s;
            cin >> s;
            for (int j = 0; j < m; ++j) {
                if (s[j] == 'R') {
                    if (j+1 < m) uf.unite(idx(i, j), idx(i, j+1));
                } else if (s[j] == 'D') {
                    if (i+1 < n) uf.unite(idx(i, j), idx(i+1, j));
                }
            }
        }
        cout << uf.groups-1 << '\n';
    }
    return 0;
}
