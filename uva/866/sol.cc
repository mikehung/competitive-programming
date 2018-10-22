#include <bits/stdc++.h>

using namespace std;

struct Point {
    int x, y;
};

struct Segment {
    Point p1, p2;
};

int t, n;
Segment s;
vector<Segment> segments;

int direction(const Point &p1, const Point &p2, const Point &p3)
{
    // https://www.geeksforgeeks.org/direction-point-line-segment
    // A: p1-p2, B: p1-p3
    // Ax * By - Ay * Bx
    return (p2.x-p1.x)*(p3.y-p1.y)-(p2.y-p1.y)*(p3.x-p1.x);
}

bool intersect(const Segment &s1, const Segment &s2)
{
    int d1 = direction(s1.p1, s1.p2, s2.p1);
    int d2 = direction(s1.p1, s1.p2, s2.p2);
    int d3 = direction(s2.p1, s2.p2, s1.p1);
    int d4 = direction(s2.p1, s2.p2, s1.p2);
    return d1 * d2 < 0 && d3 * d4 < 0;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> t;
    while (t--) {
        cin >> n;
        segments.clear();
        for (int i = 0; i < n; ++i) {
            cin >> s.p1.x >> s.p1.y >> s.p2.x >> s.p2.y;
            segments.push_back(s);
        }
        int ans = n;
        for (int i = 0; i < n; ++i) {
            for (int j = i+1; j < n; ++j) {
                if (intersect(segments[i], segments[j]))
                    ans += 2;
            }
        }
        cout << ans << '\n';
        if (t) cout << '\n';
    }
    return 0;
}
