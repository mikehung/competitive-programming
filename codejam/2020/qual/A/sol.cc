#include <bits/stdc++.h>

using namespace std;

void solve()
{
    int n;
    cin >> n;
    vector<vector<int>> ma(n, vector<int>(n));
    for (int r = 0; r < n; ++r) for (int c = 0; c < n; ++c) {
        cin >> ma[r][c];
    }
    int k = 0, r = 0, c = 0;
    for (int i = 0; i < n; ++i) {
        k += ma[i][i];
    }
    for (int i = 0; i < n; ++i) {
        bool dup = false;
        vector<bool> exist(n+1);
        for (int j = 0; j < n; ++j) {
            if (exist[ma[i][j]] == 1) {
                dup = true;
                break;
            }
            exist[ma[i][j]] = 1;
        }
        if (dup) {
            ++r;
        }
    }
    for (int i = 0; i < n; ++i) {
        bool dup = false;
        vector<bool> exist(n+1);
        for (int j = 0; j < n; ++j) {
            if (exist[ma[j][i]] == 1) {
                dup = true;
                break;
            }
            exist[ma[j][i]] = 1;
        }
        if (dup) {
            ++c;
        }
    }

    cout << k << ' ' << r << ' ' << c << '\n';
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout << fixed << setprecision(6);
    int T;
    cin >> T;
    for (int t = 1; t <= T; ++t) {
        cout << "Case #" << t << ": ";
        solve();
    }
    return 0;
}
