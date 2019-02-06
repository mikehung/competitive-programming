#include <bits/stdc++.h>

using namespace std;

const int MAX = 1e5+11, MMAX = 211;
int n, m, k, coin[MAX], until[MAX];
long long dp[MAX][MMAX];

long long calc(int t, int d)
{
    if (t > n) return 0;
    if (dp[t][d] != -1) return dp[t][d];
    if (!coin[t]) return calc(t+1, d);
    long long v = coin[t] + calc(until[t]+1, d);
    if (d) v = min(v, calc(t+1, d-1));
    return dp[t][d] = v;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    for (int i = 0; i < MAX; ++i) for (int j = 0; j < MMAX; ++j) dp[i][j] = -1;
    cin >> n >> m >> k;
    for (int i = 0; i < k; ++i) {
        int s, t, d, w;
        cin >> s >> t >> d >> w;
        for (int j = s; j <= t; ++j) {
            if (w > coin[j] || (w == coin[j] && d > until[j])) {
                coin[j] = w;
                until[j] = d;
            }
        }
    }
    cout << calc(1, m) << endl;
    return 0;
}
