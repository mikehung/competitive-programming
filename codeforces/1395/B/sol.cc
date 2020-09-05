#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, m, sx, sy;
    cin >> n >> m >> sx >> sy;
    cout << sx << ' ' << sy << '\n';
    for (int c = 2; c <= m; ++c) {
        if (c != sy) {
            cout << sx << ' ' << c << '\n';
        }
    }
    cout << sx << ' ' << 1 << '\n';
    bool dir = 0;
    for (int r = 1; r <= n; ++r) if (r != sx) {
        if (dir == 0) {
            for (int c = 1; c <= m; ++c) {
                cout << r << ' ' << c << '\n';
            }
        } else {
            for (int c = m; c > 0; --c) {
                cout << r << ' ' << c << '\n';
            }
        }
        dir = 1-dir;
    }
    return 0;
}
