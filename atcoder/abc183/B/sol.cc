#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    double sx, sy, gx, gy;
    cin >> sx >> sy >> gx >> gy;
    if (sx > gx) {
        swap(sx, gx);
        swap(sy, gy);
    }

    auto calc = [&](double m) {
        return (m-sx)/sy * gy + m;
    };

    double l = sx, r = gx;
    for (int z = 0; z < 100; ++z) {
        double m = (l+r)/2.0;
        if (calc(m) < gx) {
            l = m;
        } else {
            r = m;
        }
    }
    cout << fixed << setprecision(12) << l << '\n';
    return 0;
}
