#include <bits/stdc++.h>

using namespace std;

const int M = 1e9+7;
typedef long long ll;

long long mpow(long long a, long long b)
{
    if (b == 0) return 1;
    if (b % 2 == 0) {
        long long memo = mpow(a, b/2);
        return memo * memo % M;
    } else {
        return a * mpow(a, b-1) % M;
    }
}

long long nCr(long long n, long long r)
{
    long long an = 1;
    for (long long i = 0; i < r; ++i) {
        an *= (n-i);
        an %= M;
        an *= mpow(r-i, M-2);
        an %= M;
    }
    return an;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    long long n, a, b;
    cin >> n >> a >> b;
    long an = mpow(2, n) - 1;
    an -= nCr(n, a);
    an %= M;
    if (an < 0) an += M;
    an -= nCr(n, b);
    an %= M;
    if (an < 0) an += M;
    cout << an << endl;

    return 0;
}
