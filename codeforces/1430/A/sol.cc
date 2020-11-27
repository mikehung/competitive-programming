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
        bool ok = false;
        for (int i = 0; !ok && i <= n/3; ++i) for (int j = 0; !ok && j <= n/5; ++j) for (int k = 0; !ok && k <= n/5; ++k) {
            if (n == 3*i + 5*j + 7*k) {
                cout << i << ' ' << j << ' ' << k << '\n';
                ok = true;
            }
        }
        if (!ok) cout << -1 << '\n';
    }
    return 0;
}
