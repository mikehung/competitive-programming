#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    ll n, r;
    int t;
    cin >> t;
    while (t--) {
        cin >> n >> r;
        if (n > r) {
            cout << (1+r)*r/2 << '\n';
        } else {
            cout << 1ll+(n-1)*n/2 << '\n';
        }
    }
    return 0;
}
