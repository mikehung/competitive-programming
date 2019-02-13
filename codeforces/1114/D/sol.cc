#include <bits/stdc++.h>

using namespace std;

const int MAX = 5011;
int n, c[MAX], dp[MAX][MAX][2];

int d(int x, int y)
{
    return int(c[x] != c[y]);
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n;
    for (int i = 0; i < MAX; ++i) for (int j = 0; j < MAX; ++j) for (int k = 0; k < 2; ++k) {
        dp[i][j][k] = i == j ? 0 : MAX;
    }
    for (int i = 1; i <= n; ++i) {
        cin >> c[i];
    }

    // 0: c[l], 1: c[r]
    for (int sz = 2; sz <= n; ++sz) {
        for (int l = 1, r = l+sz-1; r <=n; ++l, ++r) {
            dp[l][r][0] = min(dp[l+1][r][0] + d(l, l+1), dp[l+1][r][1] + d(l, r));
            dp[l][r][1] = min(dp[l][r-1][0] + d(r, l), dp[l][r-1][1] + d(r, r-1));
        }
    }
    cout << min(dp[1][n][0], dp[1][n][1]) << '\n';
    return 0;
}
