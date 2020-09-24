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
        ll x1, y1, z1, x2, y2, z2, an;
        cin >> x1 >> y1 >> z1 >> x2 >> y2 >> z2;
        if (x1 >= z2) {
            an = 2*min(z1, y2);
        } else {
            z2 -= x1;
            if (z1 >= z2) {
                an = 2*min(z1-z2, y2);
            } else {
                an = 2*(z1-z2);
            }
        }
        cout << an << '\n';
    }
    return 0;
}
