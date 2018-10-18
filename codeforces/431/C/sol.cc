#include <bits/stdc++.h>
using namespace std;

#ifdef DEBUG
    #define dbg(...) fprintf(stderr, __VA_ARGS__)
#else
    #define dbg(...)
#endif

const int MAX = 105, mod = 1000000007;
int n, k, d, dp[MAX][2];
long long ans;



int solve(int n, bool ok)
{
    if (n < 0) return 0;
    if (!n) return int(ok);
    if (dp[n][ok] != -1) return dp[n][ok];
    long long v = 0;
    for (int j = 1; j <= k; ++j) {
        v += solve(n-j, ok | (j >= d));
        v %= mod;
    }
    return dp[n][ok] = v;
}


int main()
{
    cin >> n >> k >> d;
    for (int i = 0; i < MAX; ++i)
        for (int j = 0; j < 2; ++j)
            dp[i][j] = -1;
    solve(n, false);
    cout << dp[n][false] << '\n';
    return 0;
}
