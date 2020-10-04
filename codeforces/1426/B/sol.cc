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
        int n, m;
        cin >> n >> m;
        bool ok1 = false, ok2 = false;
        for (int i = 0; i < n; ++i) {
            int a, b, c, d;
            cin >> a >> b >> c >> d;
            if (a == d && b == c) ok1 = true;
            if (b == c) ok2 = true;
        }
        if (m % 2) {
            cout << "NO\n";
        } else {
            cout << (ok2 ? "YES" : "NO") << '\n';
        }
    }
    return 0;
}
