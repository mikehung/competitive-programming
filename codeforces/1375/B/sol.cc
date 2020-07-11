#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t, n, m;
    cin >> t;
    while (t--) {
        cin >> n >> m;
        vector<vector<int>> a(n, vector<int>(m));
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (i == 0 || i == n-1 || j == 0 || j == m-1) {
                    if (i != 0 && i != n-1) {
                        a[i][j] = 3;
                    } else if (j != 0 && j != m-1) {
                        a[i][j] = 3;
                    } else {
                        a[i][j] = 2;
                    }
                } else {
                    a[i][j] = 4;
                }
            }
        }
        bool ok = true;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                int x;
                cin >> x;
                if (x > a[i][j]) ok = false;
            }
        }
        if (ok) {
            cout << "YES\n";
            for (int i = 0; i < n; ++i) {
                for (int j = 0; j < m; ++j) {
                    cout << a[i][j] << ' ';
                }
                cout << '\n';
            }
        } else {
            cout << "NO\n";
        }
    }
    return 0;
}
