#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t, sx, sy, ex, ey;
    cin >> t >> sx >> sy >> ex >> ey;
    int cnt1 = abs(sx - ex), cnt2 = abs(sy - ey), cnt = cnt1 + cnt2;
    char ch1 = sx > ex ? 'W' : 'E', ch2 = sy > ey ? 'S' : 'N';
    for (int i = 1; i < t; ++i) {
        char ch;
        cin >> ch;
        if (ch == ch1) {
            if (--cnt1 >= 0) {
                if (--cnt == 0) {
                    cout << i << '\n';
                    return 0;
                }
            }
        } else if (ch == ch2) {
            if (--cnt2 >= 0) {
                if (--cnt == 0) {
                    cout << i << '\n';
                    return 0;
                }
            }
        }
    }
    cout << -1 << '\n';

    return 0;
}
