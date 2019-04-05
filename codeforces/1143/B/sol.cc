#include <bits/stdc++.h>

using namespace std;

int n;
vector<int> a;
int dp[15][10][2];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n;
    while (n) {
        a.push_back(n % 10);
        n /= 10;
    }
    reverse(a.begin(), a.end());
    int sz = a.size();
    for (int i = 0; i < sz; ++i) {
        dp[i][0][i == 0] = 1;
        for (int d1 = 0; d1 < 10; ++d1) {
            for (int f = 0; f < 2; ++f) if (dp[i][d1][f]) {
                for (int d2 = 0; d2 < (f ? a[i]+1 : 10); ++d2) {
                    int nf = f && (d2 == a[i]);
                    dp[i+1][d2][nf] = max(dp[i+1][d2][nf], dp[i][d1][f] * d2);
                }
            }
        }
    }
    int an = 0;
    for (int d = 0; d < 10; ++d) for (int f = 0; f < 2; ++f) {
        an = max(an, dp[sz][d][f]);
    }
    cout << an << endl;
    return 0;
}
