#include <bits/stdc++.h>

using namespace std;

const int M = 1e9+7;
long long l, r;

long long calc(long long n)
{
    long long odd = 0, even = 0, iter = 0;
    while (n) {
        long long mn = min((1ll<<iter), n);
        n -= mn;
        if (iter & 1) even += mn;
        else odd += mn;
        ++iter;
    }
    odd %= M;
    even %= M;
    long long an1 = (odd * odd) % M;
    long long an2 = (((even * even) % M + even) % M);
    return (an1 + an2) % M;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> l >> r;
    cout << ((calc(r) - calc(l-1)) % M + M) % M<< endl;
    return 0;
}
