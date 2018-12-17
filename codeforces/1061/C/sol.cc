#include <bits/stdc++.h>

using namespace std;

const int MAX = 1e6+112, M = 1e9+7;
int n, a;
long long dp[MAX], ans;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n;
    dp[0] = 1;
    for (int i = 0; i < n; ++i) {
        cin >> a;
        vector<int> f1, f2;
        for (int j = 1; j*j <= a; ++j) if (a % j == 0){
            f1.push_back(j);
            if (j*j != a) f2.push_back(a/j);
        }
        for (int j = f1.size()-1; j >= 0; --j) {
            f2.push_back(f1[j]);
        }
        for (auto j: f2) {
            (dp[j] += dp[j-1]) %= M;
        }
    }
    for (int i = 1; i < MAX; ++i)
        (ans += dp[i]) %= M;
    cout << ans << '\n';
    return 0;
}
