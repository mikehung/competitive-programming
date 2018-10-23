#include <bits/stdc++.h>

using namespace std;

long double distance2(long double x1, long double y1, long double x2, long double y2)
{
    return (x1-x2)*(x1-x2)+(y1-y2)*(y1-y2);
}

long double get_angle(long double x1, long double y1, long double u1, long double  v1, long double x2, long double y2)
{
    long double a = distance2(x1, y1, u1, v1);
    long double b = distance2(x1, y1, x2, y2);
    long double c = distance2(u1, v1, x2, y2);
    long double r = acos((a+b-c)/2.0/sqrt(a*b));
    return fminl(r, 2*M_PI - r);
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    long double x1, y1, x2, y2, u1, v1, u2, v2, a1, a2;
    cin >> t;
    while (t--) {
        cin >> x1 >> y1 >> u1 >> v1 >> x2 >> y2 >> u2 >> v2;
        a1 = get_angle(x1, y1, u1, v1, x2, y2);
        a2 = get_angle(x2, y2, u2, v2, x1, y1);
        if (fabs(a1 - a2) <= 1e-15)
            cout << 0 << '\n';
        else if (a1 > a2)
            cout << "Heroine\n";
        else
            cout << "Hero\n";
    }
    return 0;
}
