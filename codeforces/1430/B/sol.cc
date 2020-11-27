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
        int n, k;
        cin >> n >> k;
        vector<ll> a(n);
        for (auto &it: a) cin >> it;
        sort(a.rbegin(), a.rend());

        ll an = 0;
        for (int i = 0; i <= k; ++i) an += a[i];
        cout << an << '\n';
    }
    return 0;
}
