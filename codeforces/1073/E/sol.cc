#include <bits/stdc++.h>

using namespace std;

const int MOD = 998244353, MAX_N = 22, MAX_D = 10, MAX_MASK = 1<<10;
long long l, r;
int k, n;
string s;
long long pw[MAX_N], dp[MAX_N][MAX_MASK][2], sdp[MAX_N][MAX_MASK][2];

long long add(long long a, long long b)
{
    return ((a + b) % MOD + MOD) % MOD;
}

long long mul(long long a, long long b)
{
    return ((a * b) % MOD + MOD)  % MOD;
}

void init()
{
    pw[0] = 1;
    for (int i = 1; i < MAX_N; ++i)
        pw[i] = mul(10, pw[i-1]);
}

bool ok(int mask)
{
    int cnt = k;
    while (mask) {
        mask &= (mask-1);
        cnt--;
    }
    return cnt >= 0;
}

long long calc(long long n)
{
    s = to_string(n);
    n = s.size();
    for (int i = 0; i < MAX_N; ++i) for (int j = 0; j < MAX_MASK; ++j) for (int k = 0; k < 2; ++k) {
        dp[i][j][k] = sdp[i][j][k] = 0;
    }
    dp[0][0][1] = 1;
    for (int i = 0; i < n; ++i) for (int mask = 0; mask < MAX_MASK; ++mask) for (int f = 0; f < 2; ++f) for (int ndig = 0; ndig < (f ? s[i]-'0'+1 : MAX_D); ++ndig) {
        int nmask = mask | (1 << ndig);
        if (mask == 0 && ndig == 0) nmask = 0;  // for leading zero
        int nf = (f && (s[i]-'0') == ndig);
        dp[i+1][nmask][nf] = add(dp[i+1][nmask][nf], dp[i][mask][f]);
        sdp[i+1][nmask][nf] = add(add(sdp[i+1][nmask][nf], sdp[i][mask][f]), mul(ndig, mul(pw[n-i-1], dp[i][mask][f])));
    }

    long long res = 0;
    for (int mask = 0; mask < MAX_MASK; ++mask) {
        if (ok(mask)) {
            for (int f = 0; f < 2; ++f) {
                res = add(res, sdp[n][mask][f]);
            }
        }
    }
    return res;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> l >> r >> k;
    init();
    cout << add(calc(r), -calc(l-1)) << '\n';
    return 0;
}
