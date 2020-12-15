#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    ll n, m, t;
    cin >> n >> m >> t;
    ll battery = n, pre = 0;
    for (int i = 0; i < m; ++i) {
        ll a, b;
        cin >> a >> b;
        battery -= a-pre;
        if (battery <= 0) {
            cout << "No\n";
            return 0;
        }
        pre = b;
        battery += b-a;
        if (battery > n) battery = n;
    }
    battery -= t-pre;
    cout << (battery <= 0 ? "No" : "Yes") << '\n';
    return 0;
}
