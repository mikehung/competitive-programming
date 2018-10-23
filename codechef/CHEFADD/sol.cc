#include <bits/stdc++.h>

using namespace std;

const int MAX_BITS = 35;
long long dp[MAX_BITS][MAX_BITS][MAX_BITS][2];
int t, a, b, c;

int cnt_bits(int x)
{
    int ans = 0;
    while (x) {
        ans++;
        x &= (x-1);
    }
    return ans;
}

void init()
{
    for (int i = 0; i < MAX_BITS; ++i) for (int j = 0; j < MAX_BITS; ++j)
    for (int k = 0; k < MAX_BITS; ++k) for (int l = 0; l < 2; ++l)
        dp[i][j][k][l] = -1;
}

long long calc(int pos, int ca, int cb, int carry)
{
    if (dp[pos][ca][cb][carry] != -1)
        return dp[pos][ca][cb][carry];
    if (ca < 0 || cb < 0)
        return 0;
    if (pos == 32)
        return ca == 0 && cb == 0 && carry == 0;
    long long ans;
    if (!!(c & (1<<pos)) == carry) {
        if (carry)
            ans = calc(pos+1, ca, cb, 0) + calc(pos+1, ca-1, cb-1, 1);
        else
            ans = calc(pos+1, ca, cb, 0) + calc(pos+1, ca-1, cb-1, 1);
    } else {
        if (carry)
            ans = calc(pos+1, ca, cb-1, 1) + calc(pos+1, ca-1, cb, 1);
        else
            ans = calc(pos+1, ca, cb-1, 0) + calc(pos+1, ca-1, cb, 0);
    }
    return dp[pos][ca][cb][carry] = ans;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> t;
    while (t--) {
        init();
        cin >> a >> b >> c;
        int ca = cnt_bits(a), cb = cnt_bits(b);
        cout << calc(0, ca, cb, 0) << '\n';
    }
    return 0;
}
