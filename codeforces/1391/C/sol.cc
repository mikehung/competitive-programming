#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    ll n;
    cin >> n;
    const int M = (int) 1e9+7;
    ll an = 1, sub = 1;
    for (ll i = 2; i <= n; ++i) {
        an = (an * i) % M;
    }
    for (ll i = 0; i < n-1; ++i) {
        sub = (2 * sub) % M;
    }
    an = (an - sub) % M;
    cout << (an + M) % M << '\n';
    return 0;
}
