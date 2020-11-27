#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int tt;
    cin >> tt;
    while (tt--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> ma(n, vector<int>(m));
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                cin >> ma[i][j];
            }
        }
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (i > 0 && ma[i][j] == ma[i-1][j]) {
                    ma[i][j]++;
                } else if (j > 0 && ma[i][j] == ma[i][j-1]) {
                    ma[i][j]++;
                }
                cout << ma[i][j] << ' ';
            }
            cout << '\n';
        }
    }

    return 0;
}
