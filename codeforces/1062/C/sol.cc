#include <bits/stdc++.h>

using namespace std;

const int MAX = 1e5 + 112, MOD = 1e9 + 7;
int n, q, cnt[MAX], pw[MAX];
string s;

int calc(int x, int y)
{
    return (1LL * (pw[x]-1) * pw[y]) % MOD;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> q >> s;
    pw[0] = 1;
    for (int i = 0; i < n; ++i) {
        cnt[i+1] = cnt[i] + (s[i] == '1');
        pw[i+1] = (2LL * pw[i]) % MOD;
    }
    while (q--) {
        int l, r, x, y;
        cin >> l >> r;
        x = cnt[r] - cnt[l-1];
        y = r - l + 1 - x;
        cout << calc(x, y) << '\n';
    }
    return 0;
}
