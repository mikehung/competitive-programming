#include <bits/stdc++.h>

using namespace std;
using ll = long long;

map<ll, ll> factors(ll x)
{
    map<ll, ll> an;
    while (x % 2 == 0) {
        an[2]++;
        x /= 2;
    }
    for (ll i = 3; i*i <= x; i += 2) {
        while (x % i == 0) {
            an[i]++;
            x /= i;
        }
    }
    if (x > 2) an[x]++;
    return an;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int tt;
    cin >> tt;
    while (tt--) {
        ll a, b;
        cin >> a >> b;
        if (a % b != 0) {
            cout << a << '\n';
        } else {
            map<ll, ll> m2 = factors(b);
            ll an = 1;
            for (auto &kv: m2) {
                ll bak = a;
                while (a % b == 0) a /= kv.first;
                an = max(an, a);
                a = bak;
            }
            cout << an << '\n';
        }
    }
    return 0;
}
