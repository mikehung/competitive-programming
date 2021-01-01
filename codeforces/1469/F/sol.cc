#include <bits/stdc++.h>

using namespace std;
using ll = long long;

const int N = (int)2e5+7;
const bool MULTI_TESTCASES = 0;

struct segtree {
    int sz;
    vector<ll> cnt, lazy;

    segtree(int n) {
        sz = 1;
        while (sz < n) sz *= 2;
        cnt.resize(2*sz);
        lazy.resize(2*sz);
    }

    void push_down(int x, int lx, int rx) {
        if (lx+1 == rx || lazy[x] == 0) return;
        int m = (lx+rx)/2;
        lazy[2*x+1] += lazy[x];
        cnt[2*x+1] += lazy[x] * (m-lx);
        lazy[2*x+2] += lazy[x];
        cnt[2*x+2] += lazy[x] * (rx-m);

        lazy[x] = 0;
        cnt[x] = cnt[2*x+1] + cnt[2*x+2];
    }

    void pop_up(int x, int lx, int rx) {
        if (lx+1 == rx) return;
        cnt[x] = cnt[2*x+1] + cnt[2*x+2];
    }

    void update(int l, int r, int v, int x, int lx, int rx) {
        push_down(x, lx, rx);
        if (r <= lx || rx <= l) {
            return;
        }
        if (l <= lx && rx <= r) {
            cnt[x] += v * (rx-lx);
            lazy[x] = v;
            return;
        }
        int m = (lx+rx)/2;
        update(l, r, v, 2*x+1, lx, m);
        update(l, r, v, 2*x+2, m, rx);
        pop_up(x, lx, rx);
    }

    void update(int l, int r, int v) {
        update(l, r, v, 0, 0, sz);
    }

    ll kth(int k, int x, int lx, int rx) {
        push_down(x, lx, rx);
        if (lx+1 == rx) {
            return lx;
        }
        int m = (lx+rx)/2, an;
        if (k < cnt[2*x+1]) {
            an = kth(k, 2*x+1, lx, m);
        } else {
            an = kth(k-cnt[2*x+1], 2*x+2, m, rx);
        }
        pop_up(x, lx, rx);
        return an;
    }

    ll kth(int k) {
        return kth(k, 0, 0, sz);
    }
};

void solve()
{
    ll n, k;
    cin >> n >> k;
    vector<ll> a(n);
    for (auto &it: a) cin >> it;
    sort(a.rbegin(), a.rend());

    ll cnt = 1, an = LONG_MAX;
    segtree st(2*N);
    st.update(0, 1, 1);

    for (int i = 0; i < n; ++i) {
        cnt += a[i]-2;

        int x = st.kth(0);
        st.update(x, x+1, -1);

        if (a[i] % 2) {
            st.update(x+2, x+2+(a[i]-1)/2, 2);
        } else {
            st.update(x+2, x+2+(a[i]-1)/2, 1);
            st.update(x+2, x+2+(a[i]-1)/2+1, 1);
        }

        if (cnt >= k) {
            an = min(an, st.kth(k-1));  // zero-based
        }
    }

    cout << (cnt < k ? -1 : an) << '\n';
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int testcases = 1;
    if (MULTI_TESTCASES) cin >> testcases;
    while (testcases--) solve();
    return 0;
}
