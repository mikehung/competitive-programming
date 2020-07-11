#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t, x, y, n;
    cin >> t;
    while (t--) {
        cin >> x >> y >> n;
        int mod = n % x;
        if (mod > y) {
            n -= (mod-y);
        } else if (mod < y) {
            n -= (mod-y)+x;
        }
        cout << n << '\n';
    }
    return 0;
}
