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
        vector<int> a(n);
        vector<bool> dp(n);
        for (auto &it: a) cin >> it;
        dp[n-1] = true;
        for (int i = n-2; i >= 0; --i) {
            if (!dp[i+1]) {
                dp[i] = true;
            } else {
                dp[i] = a[i] > 1;
            }
        }
        cout << (dp[0] ? "First" : "Second") << '\n';
    }
    return 0;
}
