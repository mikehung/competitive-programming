#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        vector<vector<int>> a(n, vector<int>(n));
        vector<int> r(n), c(n);
        int x = 0, y = 0, i = 0;
        while (i < k) {
            a[x%n][y%n] = 1;
            r[x%n]++;
            c[y%n]++;
            x++, y++;
            ++i;
            if (i % n == 0) {
                x = 0, y = i/n;
            }
        }
        int mnr = r[0], mxr = r[0], mnc = c[0], mxc = c[0];
        for (int i = 1; i < n; ++i) {
            mnr = min(mnr, r[i]);
            mxr = max(mxr, r[i]);
            mnc = min(mnc, c[i]);
            mxc = max(mxc, c[i]);
        }
        cout << 1ll*(mxr-mnr)*(mxr-mnr)+1ll*(mxc-mnc)*(mxc-mnc) << '\n';
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                cout << a[i][j];
            }
            cout << '\n';
        }
    }
    return 0;
}
