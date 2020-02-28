#include <bits/stdc++.h>

using namespace std;

int h, n, dp[10000], a[1000], b[1000];

int dfs(int h)
{
    if (h <= 0) return 0;
    if (dp[h] == 0) {
        int an = 1e9;
        for (int i = 0; i < n; ++i) {
            an = min(an, dfs(h-a[i]) + b[i]);
        }

        dp[h] = an;
    }

    return dp[h];
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> h >> n;
    for (int i = 0; i < n; ++i) {
        cin >> a[i] >> b[i];
    }

    memset(dp, 0, sizeof(dp));
    cout << dfs(h) << endl;

    return 0;
}
