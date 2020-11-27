#include <bits/stdc++.h>

using namespace std;
using ll = long long;

bool is_prime(ll x)
{
    if (x == 1) return false;
    for (ll i = 2; i*i <= x; ++i) if (x % i == 0) return false;
    return true;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int tt;
    cin >> tt;
    while (tt--) {
        int n, x;
        cin >> n;
        x = n;
        while (true) {
            if (is_prime(x) && !is_prime(x-n+1)) {
                for (int i = 0; i < n; ++i) {
                    for (int j = 0; j < n; ++j) {
                        cout << (i == j ? x-n+1 : 1) << ' ';
                    }
                    cout << '\n';
                }
                break;
            }
            ++x;
        }
    }
    return 0;
}
