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
        vector<int> a(n);
        for (auto &it: a) cin >> it;

        bool ok = true;
        vector<int> b(n), c(n);
        b[0] = a[0]; // dec
        c[0] = 0; // inc
        for (int i = 1; i < n; ++i) {
            b[i] = min(b[i-1], a[i]-c[i-1]);
            c[i] = a[i] - b[i];
            if (b[i] < 0 || c[i] < 0) {
                ok = false;
                break;
            }
        }

        cout << (ok ? "YES" : "NO") << '\n';
    }
    return 0;
}
