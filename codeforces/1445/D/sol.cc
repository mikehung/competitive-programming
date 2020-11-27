#include <bits/stdc++.h>

using namespace std;
using ll = long long;

const int M = 998244353;
const int N = 3e5+11;
ll fact[N], inv[N];

ll mpow(ll x, ll e)
{
    if (e < 0) e += M-1;
    ll an = 1;
    while (e) {
        if (e & 1) an = an * x % M;
        x = x * x % M;
        e >>= 1;
    }
    return an;
}

void init()
{
    fact[0] = 1;
    for (ll i = 1; i < N; ++i) fact[i] = fact[i-1] * i % M;
    for (ll i = 0; i < N; ++i) inv[i] = mpow(fact[i], -1);
}

ll cnk(ll n, ll k)
{
    if (k < 0 || k > n) return 0;
    return fact[n] * inv[k] % M * inv[n-k] % M;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    init();
    ll n;
    cin >> n;
    vector<ll> a(2*n);
    for (auto &it: a) cin >> it;
    sort(a.begin(), a.end());
    ll an = 0;
    for (int i = 0; i < 2*n; ++i) {
        if (i < n) {
            an -= a[i];
        } else {
            an += a[i];
        }
        an %= M;
    }
    cout << an * cnk(2*n, n) % M << '\n';
    return 0;
}
