#include <bits/stdc++.h>

using namespace std;



int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    const double PI = 3.14159265358979323846;
    double n, r;
    cin >> n >> r;
    double deg = 180.0 - (((n-2) * 180.0) / n);
    double cs = cos(deg * PI / 180.0);
    double M = 1.0 - cs;
    double a = 2.0 * M - 4.0;
    double b = 4 * r * M;
    double c = 2 * r * r * M;
    double D = sqrt(b*b-4*a*c);
    double ans1 = (-1.0 * b + D) / (2 * a);
    double ans2 = (-1.0 * b - D) / (2 * a);
    double ans = (ans1 > ans2) ? ans1 : ans2;
    cout << fixed << setprecision(7) << ans << endl;
    return 0;
}
