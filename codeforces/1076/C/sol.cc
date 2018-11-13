#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t, d;
    cin >> t;
    while (t--) {
        cin >> d;
        if (d*d - 4*d < 0) {
            cout << "N\n";
        } else {
            long double x = sqrt(d*d - 4*d);
            long double a = (d + x) / 2, b = (d - x) / 2;
            cout << fixed << setprecision(9) << "Y " << a << ' ' << b << '\n';
        }
    }
    return 0;
}
