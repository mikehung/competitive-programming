#include <bits/stdc++.h>

using namespace std;
using ll = long long;

const int M = 998244353;

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

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    vector<ll> d(n+1), odd(n+1), even(n+1);
    d[0] = 1;
    even[0] = 1;
    for (int i = 1; i <= n; ++i) {
        int j = i-1;
        if (j % 2 == 0) {
            d[i] = even[j];
            odd[i] = d[i];
        } else {
            d[i] = odd[j];
            even[i] = d[i];
        }
        odd[i] += odd[i-1];
        odd[i] %= M;
        even[i] += even[i-1];
        even[i] %= M;
    }
    cout << d[n] * mpow(2, -n) % M << endl;
    return 0;
}
