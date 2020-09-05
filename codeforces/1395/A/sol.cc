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
        ll r, g, b, w;
        cin >> r >> g >> b >> w;
        int m1, m2, m3, m4;
        m1 = r % 2;
        m2 = g % 2;
        m3 = b % 2;
        m4 = w % 2;
        bool ok = false;
        int cnt = 0;
        if (m1 == 0) ++cnt;
        if (m2 == 0) ++cnt;
        if (m3 == 0) ++cnt;
        if (cnt == 0 || cnt == 3) {
            ok = true;
        } else if (cnt == 2) {
            if (m4 == 0) {
                ok = true;
            }
        } else {
            if (m4 == 1 && r > 0 && g > 0 && b > 0) {
                ok = true;
            }
        }
        cout << (ok ? "Yes" : "No") << '\n';
    }
    return 0;
}
