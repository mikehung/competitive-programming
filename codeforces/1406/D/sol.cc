#include <bits/stdc++.h>

using namespace std;
using ll = long long;

ll calc(ll x)
{
    return x > 0 ? (x+1)/2 : x/2;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    vector<ll> diff(n), sums(2);
    ll pre, a0;
    for (int i = 0; i < n; ++i) {
        ll cur;
        cin >> cur;
        if (i == 0) {
            a0 = cur;
        } else {
            diff[i] = cur - pre;
            sums[diff[i] > 0] += diff[i];
        }
        pre = cur;
    }
    cout << (n == 1 ? calc(a0) : calc(a0+sums[1])) << '\n';

    int q;
    cin >> q;
    while (q--) {
        ll l, r, x;
        cin >> l >> r >> x;
        --l, --r;
        if (l == 0) {
            a0 += x;
        } else {
            sums[diff[l] > 0] -= diff[l];
            diff[l] += x;
            sums[diff[l] > 0] += diff[l];
        }
        if (r+1 < n) {
            sums[diff[r+1] > 0] -= diff[r+1];
            diff[r+1] -= x;
            sums[diff[r+1] > 0] += diff[r+1];
        }

        cout << (n == 1 ? calc(a0) : calc(a0+sums[1])) << '\n';
    }
    return 0;
}
