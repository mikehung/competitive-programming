#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, t;
    cin >> n >> t;
    int mn = INT_MAX, an;
    for (int i = 1; i <= n; ++i) {
        int s, d;
        cin >> s >> d;
        if (s >= t) {
            if (mn > s) {
                mn = s;
                an = i;
            }
            mn = min(mn, s);
        } else {
            int x = t - s;
            if (x % d == 0) {
                if (mn > t) {
                    mn = t;
                    an = i;
                }
            } else {
                int z = s + ((x/d)+1)*d;
                if (mn > z) {
                    mn = z;
                    an = i;
                }
            }
        }
    }
    cout << an << endl;
    return 0;
}
