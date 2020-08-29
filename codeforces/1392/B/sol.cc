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
        ll k;
        cin >> n >> k;
        vector<int> a(n);
        for (auto &it: a) {
            cin >> it;
        }
        int mx = a[0], mn = a[0];
        for (int i = 0; i < n; ++i) {
            mx = max(mx, a[i]);
            mn = min(mn, a[i]);
        }
        vector<int> an1(n), an2(n);
        for (int i = 0; i < n; ++i) {
            an1[i] = mx - a[i];
        }
        for (int i = 0; i < n; ++i) {
            an2[i] = mx-mn-an1[i];
        }
        for (int i = 0; i < n; ++i) {
            cout << (k % 2 ? an1[i] : an2[i]) << ' ';
        }
        cout << '\n';
    }
    return 0;
}
