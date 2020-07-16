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
        ll x;
        cin >> n >> x;
        vector<ll> a(n);
        for (auto &it: a) cin >> it;
        sort(a.rbegin(), a.rend());

        int an = 0;
        for (int i = 0; i < n;) {
            for (int j = i; j < n; ++j) {
                if (a[j]*(j-i+1) >= x) {
                    ++an;
                    i = j+1;
                    break;
                }
                if (j == n-1) {
                    i = n;
                }
            }
        }
        cout << an << '\n';
    }
    return 0;
}
