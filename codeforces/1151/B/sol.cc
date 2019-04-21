#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, m;
    cin >> n >> m;
    vector<int> an(n, 1);
    int r = 0;
    vector<vector<int>> a(n, vector<int>(m));
    for (int i = 0; i < n; ++i) for (int j = 0; j < m; ++j) {
        cin >> a[i][j];
        if (j == 0) r ^= a[i][0];
    }
    if (r) {
        cout << "TAK\n";
        for (auto &v: an) cout << v << ' '; cout << endl;
        return 0;
    }
    for (int r = 0; r < n; ++r) {
        for (int c = 1; c < m; ++c) {
            if (a[r][c] != a[r][0]) {
                an[r] = c+1;
                cout << "TAK\n";
                for (auto &v: an) cout << v << ' '; cout << endl;
                return 0;
            }
        }
    }
    cout << "NIE\n";
    return 0;
}
