#include <bits/stdc++.h>

using namespace std;

struct Point {
    double x, y;
};

const double pi = 3.141592653589793;
Point p1, p2, p3;

double dist(const Point &p1, const Point &p2)
{
    return sqrt((p1.x-p2.x)*(p1.x-p2.x) + (p1.y-p2.y)*(p1.y-p2.y));
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    while (cin >> p1.x >> p1.y >> p2.x >> p2.y >> p3.x >> p3.y) {
        double a = dist(p1, p2), b = dist(p2, p3), c = dist(p1, p3);
        double s = (a + b + c) / 2.0;
        double r = a*b*c / 4.0 / sqrt((s * (s-a) * (s-b) * (s-c)));
        cout << fixed << setprecision(2) << 2.0*r*pi << '\n';
    }
    return 0;
}
