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
        ll n, x, y;
        cin >> n >> x >> y;
        if (x > y) swap(x, y);
        ll diff = y-x, v = diff;
        for (ll i = 1; i <= diff; ++i) if (diff % i == 0) {
            if ((diff/i) <= n-1) {
                v = i;
                break;
            }
        }
        vector<ll> an;
        for (int i = x; i <= y; i += v) {
            an.push_back(i);
        }
        int i = x-v;
        while (an.size() < n && i > 0) {
            an.push_back(i);
            i -= v;
        }
        i = y+v;
        while (an.size() < n) {
            an.push_back(i);
            i += v;
        }
        for (auto x: an) {
            cout << x << ' ';
        }
        cout << '\n';
    }
    return 0;
}
