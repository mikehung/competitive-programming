#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    long long x, y, z, a, b, c, d;
    cin >> x >> y;
    z = abs(x) + abs(y);
    if (x > 0 && y > 0)
        a = 0, b = z, c = z, d = 0;
    else if (x > 0 && y < 0)
        a = 0, b = -z, c = z, d = 0;
    else if (x < 0 && y > 0)
        a = -z, b = 0, c = 0, d = z;
    else
        a = -z, b = 0, c = 0, d = -z;
    cout << a << ' ' << b << ' ' << c << ' ' << d << '\n';
    return 0;
}
