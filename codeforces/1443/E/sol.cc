#include <bits/stdc++.h>

using namespace std;
using ll = long long;

const int LAST_N = 14;
int n, q;
ll next_perm;
vector<ll> first, second;

ll calc_first(int l, int r)
{
    int sz = first.size();
    r = min(r, sz-1);
    l = min(l, sz-1);
    return first[r] - first[l];
}

ll calc_second(int l, int r)
{
    int fsz = first.size()-1;
    l = max(0, l-fsz), r = max(0, r-fsz);
    if (l == r) {
        return 0;
    }

    int sz = second.size();
    ll val = 1;
    vector<int> idx(sz), used(sz);
    for (int i = 0; i < sz; ++i) {
        val *= (i+1);
    }
    ll k = min(next_perm, val-1);
    for (int i = 0; i < sz; ++i) {
        val /= (sz-i);
        int j = k / val;
        k %= val;
        for (int z = 0; z < sz; ++z) if (!used[z]) {
            if (j-- == 0) {
                used[z] = 1;
                idx[i] = z;
                break;
            }
        }
    }
    ll an = 0;
    for (int i = l; i < r; ++i) {
        an += second[idx[i]];
    }
    return an;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> n >> q;
    first.push_back(0);
    for (int i = 1; i <= n; ++i) {
        if (i > n - LAST_N) {
            second.push_back(i);
        } else {
            first.push_back(i + first.back());
        }
    }

    while (q--) {
        int op;
        cin >> op;
        if (op == 1) {
            int l, r;
            cin >> l >> r;
            --l;
            cout << calc_first(l, r) + calc_second(l, r) << '\n';
        } else {
            ll x;
            cin >> x;
            next_perm += x;
        }
    }

    return 0;
}
