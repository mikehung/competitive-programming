#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--) {
        ll n;
        cin >> n;
        ll a = -1, b = -1;
        if (n % 2 == 0) {
            a = n/2, b = n/2;
        } else {
            map<ll, ll> cnt;
            for (ll i = 3; i*i <= n; i += 2) {
                while (n % i == 0) {
                    if (a == -1) {
                        a = 1, b = i-1;
                    } else {
                        a *= i, b *= i;
                    }
                    n /= i;
                }
            }
            if (n > 2) {
                if (a == -1) {
                    a = 1, b = n-1;
                } else {
                    a *= n, b *= n;
                }
            }
        }
        cout << a << ' ' << b << '\n';
    }
    return 0;
}
