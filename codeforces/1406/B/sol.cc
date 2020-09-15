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
        int n;
        cin >> n;
        vector<ll> a(n);
        for (auto &it: a) cin >> it;
        sort(a.begin(), a.end());
        ll v1 = a[0] * a[1] * a[2] * a[3] * a[n-1];
        ll v2 = a[0] * a[1] * a[n-1] * a[n-2] * a[n-3];
        ll v3 = a[n-1] * a[n-2] * a[n-3] * a[n-4] * a[n-5];
        cout << max({v1, v2, v3}) << '\n';
    }
    return 0;
}
