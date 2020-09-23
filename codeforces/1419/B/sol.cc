#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    vector<ll> f(32);
    f[1] = 1;
    for (ll i = 2; i < 32; ++i) {
        f[i] = (1ll<<(i-1)) * (1ll<<(i-1)) + 2ll * f[i-1];
    }
    for (ll i = 2; i < 32; ++i) f[i] += f[i-1];
    while (t--) {
        ll x;
        cin >> x;
        for (ll i = 1; i < 32; ++i) {
            if (f[i] > x) {
                cout << i-1 << '\n';
                break;
            }
        }
    }
    return 0;
}
