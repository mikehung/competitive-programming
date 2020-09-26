#include <bits/stdc++.h>

using namespace std;
using ll = long long;

const int M = 998244353, N = 3e5+11;
int n, k;
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

    cin >> n >> k;
    vector<pair<int, int>> events;
    for (int i = 0; i < n; ++i) {
        int l, r;
        cin >> l >> r;
        events.push_back({l, 1});
        events.push_back({r+1, -1});
    }
    sort(events.begin(), events.end());

    ll cnt = 0, an = 0;
    for (auto e: events) {
        cnt += e.second;
        if (e.second == 1) {
            an += cnk(cnt-1, k-1);
            an %= M;
        }
    }
    cout << an << '\n';
    return 0;
}
