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
    double n;
    while (cin >> n && n) {
        int lo = 0, hi = 105, mid;
        while (lo < hi) {
            mid = lo + (hi - lo + 1) / 2;
            if (mid*mid*mid <= n) {
                lo = mid;
            } else {
                hi = mid-1;
            }
        }
        double ans = (n + 2.0*lo*lo*lo) / (3.0 * lo*lo);
        cout << fixed << setprecision(4) << ans << '\n';
    }

    return 0;
}
