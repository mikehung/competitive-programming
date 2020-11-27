#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int r, n;
    cin >> r >> n;
    vector<int> t(n+1), x(n+1), y(n+1);
    t[0] = 0, x[0] = y[0] = 1;
    for (int i = 0; i < n; ++i) {
        cin >> t[i+1] >> x[i+1] >> y[i+1];
    }
    vector<int> dp(n+1), mx(n+1);
    for (int i = 1; i <= n; ++i) {
        if (x[i]-1+y[i]-1 > t[i]) {
            dp[i] = -1;
            mx[i] = mx[i-1];
            continue;
        }

        for (int j = i-1; j >= 0; --j) {
            int diff_t = t[i]-t[j];
            int diff_p = abs(x[i]-x[j]) + abs(y[i]-y[j]);
            if (diff_t > 1000) {
                dp[i] = max(dp[i], mx[j]+1);
                break;
            }
            if (diff_t >= diff_p) {
                dp[i] = max(dp[i], dp[j]+1);
            }
        }
        mx[i] = max(dp[i], mx[i-1]);
    }
    cout << mx[n] << '\n';
    return 0;
}
