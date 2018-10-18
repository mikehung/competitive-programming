#include <bits/stdc++.h>

using namespace std;

const int M = (int) 1e9 + 9;
long long n, m, k, ans;

long long f(long long exp)
{
    long long ans = 1, base = 2;
    while (exp) {
        if (exp & 1) {
            ans *= base;
            ans %= M;
        }
        base *= base;
        base %= M;
        exp /= 2;
    }
    return ans;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> m >> k;
    long long ok, bad, first, later, exp;
    ok = m;
    bad = n - m;
    later = min(m, bad * (k - 1));
    first = ok - later;
    exp = first / k;
    later += first % k;
    ans = 2 * k;
    ans %= M;
    ans *= f(exp) - 1;
    ans %= M;
    ans += later;
    ans %= M;
    cout << ans << '\n';

    return 0;
}
