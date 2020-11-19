#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int tt;
    cin >> tt;
    while (tt--) {
        int n;
        cin >> n;
        vector<pair<ll, ll>> a(n);
        for (int i = 0; i < n; ++i) {
            cin >> a[i].first;
        }
        for (int i = 0; i < n; ++i) {
            cin >> a[i].second;
        }
        sort(a.rbegin(), a.rend());
        ll an = a[0].first, pref = 0;
        for (int i = 0; i < n; ++i) {
            pref += a[i].second;
            ll cur = max(pref, (i+1 < n ? a[i+1].first : 0));
            an = min(an, cur);
        }
        cout << an << '\n';
    }
    return 0;
}
