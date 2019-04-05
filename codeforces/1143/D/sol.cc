#include <bits/stdc++.h>

using namespace std;

long long n, k, nk, a, b, x = 1e18, y = 0;
set<long long> first, second;

long long calc(long long x)
{
    int res = (x + n * k) % (n * k);
    return res ? res : nk;
}

long long gcd(long long a, long long b)
{
    if (!b) return a;
    return gcd(b, a % b);
}

long long get_step(long long p1, long long p2)
{
    long long step = p2 - p1;
    if (step <= 0) step += nk;
    return step;
}

void calc2(long long step)
{
    long long g = gcd(nk, step);
    long long r = nk / g;
    x = min(x, r);
    y = max(y, r);
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> k >> a >> b;
    nk = n * k;
    for (long long i = 0; i < n; ++i) {
        int rest = i * k + 1;
        first.insert(calc(rest-a));
        first.insert(calc(rest+a));
        second.insert(calc(rest-b));
        second.insert(calc(rest+b));
    }
    long long v1 = get_step(a, b);
    long long v2 = get_step(a, -b);
    long long v3 = get_step(-a, b);
    long long v4 = get_step(-a, -b);
    for (long long i = 0; i < n; ++i) {
        long long dis = i * k;
        calc2(dis + v1);
        calc2(dis + v2);
        calc2(dis + v3);
        calc2(dis + v4);
    }
    cout << x << ' ' << y << endl;
    return 0;
}
