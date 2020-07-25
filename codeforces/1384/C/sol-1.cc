#include <bits/stdc++.h>

using namespace std;

class dsu {
public:
    vector<int> p, r;
    int n;

    dsu(int _n): n(_n) {
        p.resize(n);
        r.resize(n);
        iota(p.begin(), p.end(), 0);
    }

    int find(int x) {
        return x == p[x] ? x : (p[x] = find(p[x]));
    }

    bool unite(int x, int y) {
        x = find(x), y = find(y);
        if (p[x] != p[y]) {
            if (r[x] < r[y]) swap(x, y);
            p[y] = p[x];
            if (r[x] == r[y]) ++r[x];
            return true;
        }
        return false;
    }
};

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int tt;
    cin >> tt;
    while (tt--) {
        int n;
        string s, t;
        cin >> n >> s >> t;
        dsu d(26);

        int an = 0;
        for (int i = 0; i < n; ++i) {
            int u = s[i]-'a', v = t[i]-'a';
            if (u > v) {
                an = -1;
                break;
            } else {
                if (d.unite(u, v)) {
                    an++;
                }
            }
        }
        cout << an << '\n';
    }
    return 0;
}
