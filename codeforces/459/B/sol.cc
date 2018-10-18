#include <bits/stdc++.h>
using namespace std;

int n, b, mx = 0, nmx, mn = 1e9+9, nmn;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> b;
        if (b > mx) {
            mx = b;
            nmx = 1;
        } else if (b == mx) {
            ++nmx;
        }
        if (b < mn) {
            mn = b;
            nmn = 1;
        } else if (b == mn) {
            ++nmn;
        }
    }
    if (mx == mn)
        cout << mx - mn << ' ' << 1LL * n * (n-1) / 2 << '\n';
    else
        cout << mx - mn << ' ' << 1LL * nmn * nmx << '\n';

    return 0;
}
