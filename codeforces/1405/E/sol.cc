#include <bits/stdc++.h>

using namespace std;

struct segtree {
    int size;
    vector<int> adds;

    segtree(int n) {
        size = 1;
        while (size < n) size *= 2;
        adds.resize(2*size);
    }

    void push_down(int x, int lx, int rx) {
        if (lx+1 == rx) return;
        adds[2*x+1] += adds[x];
        adds[2*x+2] += adds[x];
        adds[x] = 0;
    }

    void add(int l, int r, int v, int x, int lx, int rx) {
        push_down(x, lx, rx);
        if (r <= lx || rx <= l) return;
        if (l <= lx && rx <= r) {
            adds[x] += v;
            return;
        }
        int m = (lx+rx)/2;
        add(l, r, v, 2*x+1, lx, m);
        add(l, r, v, 2*x+2, m, rx);
    }

    void add(int l, int r, int v) {
        add(l, r, v, 0, 0, size);
    }

    int get(int i, int x, int lx, int rx) {
        push_down(x, lx, rx);
        if (lx+1 == rx) {
            return adds[x];
        }
        int m = (lx+rx)/2;
        if (i < m) {
            return get(i, 2*x+1, lx, m);
        } else {
            return get(i, 2*x+2, m, rx);
        }
    }

    int get(int i) {
        return get(i, 0, 0, size);
    }
};

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, q;
    cin >> n >> q;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        --a[i];
    }

    vector<int> an(q);
    map<int, vector<pair<int, int>>> mp;
    for (int i = 0; i < q; ++i) {
        int x, y;
        cin >> x >> y;
        mp[n-y-1].push_back({x, i});
    }

    segtree st(n);
    for (int r = 0; r < n; ++r) {
        int v = r - a[r];
        if (v >= 0 && st.get(0) >= v) {
            int lo = 0, hi = r+1;
            while (lo+1 < hi) {
                int mid = lo + (hi-lo)/2;
                if (st.get(mid) >= v) {
                    lo = mid;
                } else {
                    hi = mid;
                }
            }
            st.add(0, hi, 1);
        }

        for (auto &par: mp[r]) {
            an[par.second] = st.get(par.first);
        }
    }

    for (auto x: an) {
        cout << x << '\n';
    }

    return 0;
}
