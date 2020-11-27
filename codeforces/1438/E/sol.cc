#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    vector<ll> a(n);
    for (auto &it: a) cin >> it;

    ll cnt = 0;
    set<pair<int, int>> se;
    for (int l = 0; l < n-1; ++l) {
        ll k = 1;
        while (k < a[l]) k *= 2;
        ll sum = a[l+1];
        for (int r = l+2; r < n; ++r) {
            if ((a[l]^a[r]) == sum) {
                ++cnt;
                se.insert({n-1-r, n-1-l});
            }
            sum += a[r];
            if (sum >= k) {
                break;
            }
        }
    }
    reverse(a.begin(), a.end());
    for (int l = 0; l < n-1; ++l) {
        ll k = 1;
        while (k < a[l]) k *= 2;
        ll sum = a[l+1];
        for (int r = l+2; r < n; ++r) {
            if ((a[l]^a[r]) == sum) {
                if (!se.count({l, r})) ++cnt;
            }
            sum += a[r];
            if (sum >= k) {
                break;
            }
        }
    }
    cout << cnt << '\n';
    return 0;
}
