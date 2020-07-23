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
        n *= 2;
        vector<int> a(n), pos(n+1);
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
            pos[a[i]] = i;
        }

        vector<bool> used(n+1);
        vector<int> seg;
        int end = n, mx = n;
        while (mx > 0) {
            int st = pos[mx];
            seg.push_back(end-st);
            for (int i = st; i < end; ++i) {
                used[a[i]] = 1;
            }
            end = st;
            while (used[mx]) --mx;
        }

        int sz = seg.size();
        vector<vector<bool>> dp(sz+1, vector<bool>(n/2+1));
        dp[0][0] = true;
        for (int i = 0; i < sz; ++i) {
            for (int j = 0; j < n/2+1; ++j) {
                if (j >= seg[i]) {
                    dp[i+1][j] = dp[i][j] | dp[i][j-seg[i]];
                } else {
                    dp[i+1][j] = dp[i][j];
                }
            }
        }

        cout << (dp[sz][n/2] ?  "YES" : "NO") << '\n';
    }
    return 0;
}
