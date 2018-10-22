#include <bits/stdc++.h>

using namespace std;

const int MAX = 1005;
int n, xa, xb, ya, yb, za, zb, x, y, z, l;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    while (cin >> n && n) {
        cin >> x >> y >> z >> l;
        xa = x, xb = x + l;
        ya = y, yb = y + l;
        za = z, zb = z + l;
        n--;
        while (n--) {
            cin >> x >> y >> z >> l;
            xa = max(xa, x), xb = min(xb, x + l);
            ya = max(ya, y), yb = min(yb, y + l);
            za = max(za, z), zb = min(zb, z + l);
        }
        cout << max(0, xb - xa) * max(0, yb - ya) * max(0, zb - za) << '\n';
    }
    return 0;
}
