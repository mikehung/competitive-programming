#include <bits/stdc++.h>

using namespace std;

const int MAX = 2123, MOD = 1e9+7;
int m, d;
string a, b;
long long pw[MAX], dp[MAX][MAX][2];

long long add(long long a, long long b, int mod=MOD)
{
    return (((a + b) % mod) + mod) % mod;
}

long long addm(long long a, long long b)
{
    return add(a, b, m);
}

long long mul(long long a, long long b, int mod=MOD)
{
    return (((a * b) % mod) + mod) % mod;
}

long long mulm(long long a, long long b)
{
    return mul(a, b, m);
}

long long calc(const string &s)
{
    int len = s.size();
    for (int i = 0; i <= len; ++i) for (int j = 0; j < m; ++j) for (int k = 0; k < 2; ++k)
        dp[i][j][k] = 0;
    dp[0][0][1] = 1;
    for (int i = 0; i < len; ++i) for (int mod = 0; mod < m; ++mod) for (int f = 0; f < 2; ++f) {
        if (dp[i][mod][f] == 0) continue;
        int lo, hi;
        if (i & 1) {
            if (f && d > s[i]-'0') continue;
            lo = hi = d;
        } else {
            lo = (i == 0), hi = f ? s[i]-'0' : 9;
        }
        for (int dig = lo; dig <= hi; ++dig) {
            if (!(i & 1) && dig == d) continue;
            int nf = f && s[i]-'0' == dig;
            int nmod = addm(mod, mulm(dig, pw[len-i-1]));
            dp[i+1][nmod][nf] = add(dp[i+1][nmod][nf], dp[i][mod][f]);
        }
    }
    return add(dp[len][0][0], dp[len][0][1]);
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> m >> d >> a >> b;
    pw[0] = 1;
    for (int i = 1; i < MAX; ++i) {
        pw[i] = mulm(pw[i-1], 10);
    }
    int i = (int) a.size() - 1;
    while (a[i] == '0') --i;
    if (i == 0 && a[i] == '1') {
        cout << calc(b) << '\n';
    } else {
        a[i] = a[i]-'0'-1+'0';
        for (int j = i+1; j < (int) a.size(); ++j) {
            a[j] = '9';
        }
        cout << add(calc(b), -calc(a)) << '\n';
    }

    return 0;
}
