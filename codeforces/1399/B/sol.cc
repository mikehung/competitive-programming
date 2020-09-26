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
        vector<int> a(n), b(n);
        for (auto &it: a) cin >> it;
        for (auto &it: b) cin >> it;
        int x = a[0], y = b[0];
        for (int i = 0; i < n; ++i) {
            x = min(x, a[i]);
            y = min(y, b[i]);
        }
        ll an = 0;
        for (int i = 0; i < n; ++i) {
            an += max(a[i]-x, b[i]-y);
        }
        cout << an << '\n';
    }
    return 0;
}
