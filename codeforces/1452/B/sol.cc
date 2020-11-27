#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int tt;
    cin >> tt;
    while (tt--) {
        ll n;
        cin >> n;
        vector<ll> a(n);
        for (auto &it: a) cin >> it;

        sort(a.begin(), a.end());
        ll sum = accumulate(a.begin(), a.end(), 0ll);
        ll val = a.back() * (n-1);
        if (sum <= val) {
            cout << val - sum << '\n';
        } else {
            ll mod = sum % (n-1);
            cout << ((mod == 0) ? 0 : n-1-mod) << '\n';
        }
    }
    return 0;
}
