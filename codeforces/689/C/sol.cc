#include <bits/stdc++.h>
using namespace std;

#ifdef DEBUG
    #define dbg(...) fprintf(stderr, __VA_ARGS__)
#else
    #define dbg(...)
#endif

const int MAX = (int) 1e6;
long long a3[MAX];

long long cnt(long long m)
{
    long long res = 0;
    for (int i = 2; i < MAX && m/a3[i]; ++i) {
        res += m/a3[i];
    }
    return res;
}

int main()
{
    long long m, lo = 0, hi = 1e18, mid;
    for (int i = 0; i < MAX; ++i)
        a3[i] = 1LL * i * i * i;

    cin >> m;
    while (lo < hi) {
        mid = lo + (hi-lo)/2;
        if (m <= cnt(mid))
            hi = mid;
        else
            lo = mid+1;
    }
    if (cnt(lo) == m)
        cout << lo << '\n';
    else
        cout << -1 << '\n';

    return 0;
}
