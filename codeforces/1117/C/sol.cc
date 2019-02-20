#include <bits/stdc++.h>

using namespace std;

const long long INF = 1e18;
long long X1, Y1, X2, Y2, n;
string dir;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> X1 >> Y1 >> X2 >> Y2 >> n >> dir;

    long long x = 0, y = 0;
    vector<long long> px, py;
    px.push_back(0), py.push_back(0);
    for (char &c: dir) {
        if (c == 'U') ++y;
        else if (c == 'D') --y;
        else if (c == 'L') --x;
        else ++x;
        px.push_back(x);
        py.push_back(y);
    }

    long long lo = 0, hi = INF, mid;
    while (lo < hi) {
        mid = lo + (hi - lo) / 2;
        long long nx = X1 + (mid/n)*px[n] + px[(mid%n)];
        long long ny = Y1 + (mid/n)*py[n] + py[(mid%n)];
        long long d = llabs(nx - X2) + llabs(ny - Y2);
        if (mid < d) {
            lo = mid + 1;
        } else {
            hi = mid;
        }
    }
    cout << (lo == INF ? -1 : lo) << '\n';

    return 0;
}
