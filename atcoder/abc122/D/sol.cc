#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    const int M = 1e9+7;
    int n;
    cin >> n;
    long long ans = 0;
    if (n == 1) ans = 4;
    else if (n == 2) ans = 16;
    else {
        vector<vector<vector<long long>>> dp1(4, vector<vector<long long>>(4, vector<long long>(4)));
        for (int i = 0; i < 4; ++i) for (int j = 0; j < 4; ++j) for (int k = 0; k < 4; ++k) {
            dp1[i][j][k] = 1;
        }
        dp1[0][3][2] = dp1[0][2][3] = dp1[3][0][2] = 0;
        for (int x = 4; x <= n; ++x) {
            vector<vector<vector<long long>>> dp2(4, vector<vector<long long>>(4, vector<long long>(4)));
            for (int i = 0; i < 4; ++i) for (int j = 0; j < 4; ++j) for (int k = 0; k < 4; ++k) {
                for (int l = 0; l < 4; ++l) {
                    if (i == 0 && j == 3 && l == 2) continue;
                    if (i == 0 && k == 3 && l == 2) continue;

                    if (j == 0 && k == 3 && l == 2) continue;
                    if (j == 0 && k == 2 && l == 3) continue;
                    if (j == 3 && k == 0 && l == 2) continue;
                    dp2[j][k][l] += dp1[i][j][k];
                    dp2[j][k][l] %= M;
                }
            }
            swap(dp1, dp2);
        }
        for (int i = 0; i < 4; ++i) for (int j = 0; j < 4; ++j) for (int k = 0; k < 4; ++k) {
            ans += dp1[i][j][k];
            ans %= M;
        }
    }
    cout << ans << endl;
    return 0;
}
