#include <bits/stdc++.h>
using namespace std;

#ifdef DEBUG
    #define dbg(...) fprintf(stderr, __VA_ARGS__)
#else
    #define dbg(...)
#endif

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    long long n, m, mn, mx;
    cin >> n >> m;
    mn = max(0LL, n - 2*m);
    if (m == 0) {
        mx = n;
    } else {
        long long k = 1;
        for (; k <= n; ++k) {
            if (k*(k-1) >= 2*m)
                break;
        }
        mx = n - k;
    }
    cout << mn << ' ' << mx << '\n';

    return 0;
}
