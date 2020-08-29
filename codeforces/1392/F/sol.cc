#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    ll n;
    cin >> n;
    ll sum = 0;
    for (int i = 0; i < n; ++i) {
        ll x;
        cin >> x;
        sum += x;
    }
    ll A = (n*(n-1)) / 2;
    for (int i = 0; i < n; ++i) {
        if ((sum-A+i) % n == 0) {
            ll a0 = (sum-A+i)/n;
            for (int j = 0; j < n-i; ++j) {
                cout << a0+j << ' ';
            }
            for (int j = n-i; j < n; ++j) {
                cout << a0+j-1 << ' ';
            }
            return 0;
        }
    }
    return 0;
}
