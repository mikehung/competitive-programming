#include <bits/stdc++.h>

using namespace std;

const int MAX = 1e5 + 112, AMAX = 1e6 + 12, M = 1e9 + 7;
int n, a[MAX];
long long dp[AMAX];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n;
    for (int i = 1; i <= n; ++i)
        cin >> a[i];
    dp[0] = 1;
    for (int i = 1; i <= n; ++i) {
        vector<int> x, y;
        for (int j = 1; j*j <= a[i]; ++j) if (a[i] % j == 0) {
            x.push_back(j);
            if (j*j != a[i]) y.push_back(a[i]/j);
        }
        for (int j = x.size()-1; j >= 0; --j)
            y.push_back(x[j]);
        for (auto j: y)
            (dp[j] += dp[j-1]) %= M;
    }
    long long ans = 0;
    for (int i = 1; i < AMAX; ++i)
        (ans += dp[i]) %= M;
    cout << ans << '\n';
    return 0;
}
