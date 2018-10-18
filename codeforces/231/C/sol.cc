#include <bits/stdc++.h>
using namespace std;

#ifdef DEBUG
    #define dbg(...) fprintf(stderr, __VA_ARGS__)
#else
    #define dbg(...)
#endif

const int MAX = (int) 1e5 + 10;
int n, k, a[MAX], ans, cur, x;
long long p[MAX];

int solve(int i)
{
    int lo = 1, hi = i, mid;
    while (lo < hi) {
        mid = lo + (hi - lo + 1) / 2;
        if (1LL*a[i]*mid - (p[i]-p[i-mid]) <= k)
            lo = mid;
        else
            hi = mid-1;
    }
    return lo;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> k;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
    }
    sort(a+1, a+n+1);
    for (int i = 1; i <= n; ++i) {
        p[i] = a[i] + p[i-1];
    }
    for (int i = 1; i <= n; ++i) {
        cur = solve(i);
        if (cur > ans) {
            ans = cur;
            x = a[i];
        }
    }
    cout << ans << ' ' << x << '\n';

    return 0;
}
