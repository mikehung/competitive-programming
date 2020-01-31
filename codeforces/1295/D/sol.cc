#include <bits/stdc++.h>

using namespace std;

long long a, m, k;
vector<long long> fa;

long long gcd(long long a, long long b)
{
    if (b == 0) return a;
    return gcd(b, a%b);
}

void f1()
{
    long long n = m/k;
    if (n % 2 == 0) {
        fa.push_back(2);
        while (n % 2 == 0) n /= 2;
    }
    for (long long x = 3; x*x <= n; x += 2) {
        if (n % x == 0) {
            fa.push_back(x);
            while (n % x == 0) n /= x;
        }
    }
    if (n > 2) fa.push_back(n);
    // cerr << "fa: "; for (auto &v: fa) cerr << v << ' '; cerr << endl;
}

long long cnt(long long n)
{
    long long sz = 1 << fa.size(), an = 0;
    for (int i = 0; i < sz; ++i) {
        long long v = 1, sign = 1;
        for (int j = 0; j < fa.size(); ++j) {
            if (i & (1 << j)) {
                v *= fa[j];
                sign *= -1;
            }
        }
        // cerr << "  i, sign, v: " << i << ' ' << sign << ' ' << v << endl;
        an += sign *  n / v;
    }
    return an;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int T;
    cin >> T;
    while (T--) {
        cin >> a >> m;
        k = gcd(a, m);
        fa.clear();
        // cerr << "amk: " << a << ' ' << m << ' ' << k << '\n';

        f1();
        cout << cnt((a+m-1)/k) - cnt(a/k-1) << '\n';
    }
    return 0;
}
