#include <bits/stdc++.h>

using namespace std;

const int MOD = 998244353, MAX = 2002;
int n, m, k;
long long C[MAX][MAX];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> n >> m >> k;
    for (int i = 0; i < n; ++i)
        C[i][i] = C[i][0] = 1;
    for (int i = 1; i < n; ++i)
        for (int j = 1; j < i; ++j)
            C[i][j] = (C[i-1][j-1] + C[i-1][j]) % MOD;

    long long ans = m;
    for (int i = 0; i < k; ++i) {
        ans *= (m - 1);
        ans %= MOD;
    }
    ans *= C[n-1][k];
    ans %= MOD;
    cout << ans << '\n';

    return 0;
}
