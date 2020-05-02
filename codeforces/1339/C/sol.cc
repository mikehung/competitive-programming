#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int mx = INT_MIN, diff = 0;
        for (int i = 0; i < n; ++i) {
            int x;
            cin >> x;
            if (x < mx) diff = max(diff, mx - x);
            else mx = max(mx, x);
        }

        if (diff == 0) {
            cout << 0 << '\n';
            continue;
        }

        for (int i = 31; i >= 0; --i) {
            if ((diff >> i) & 1) {
                cout << i+1 << '\n';
                break;
            }
        }
    }
    return 0;
}
