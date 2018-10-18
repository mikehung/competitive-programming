#include <bits/stdc++.h>
using namespace std;

#ifdef DEBUG
    #define dbg(...) fprintf(stderr, __VA_ARGS__)
#else
    #define dbg(...)
#endif

bool check(long long x, long long y) {
    long long lo = 1, hi = 1e6, mid, z, xy = x * y;
    while (lo < hi) {
        mid = lo + (hi - lo) / 2;
        if (mid*mid*mid < xy) {
            lo = mid + 1;
        } else {
            hi = mid;
        }
    }
    z = lo;
    return z*z*z == xy && (x % z) == 0 && (y % z) == 0;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, x, y;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> x >> y;
        if (check(x, y)) {
            puts("Yes");
        } else {
            puts("No");
        }
    }

    return 0;
}
