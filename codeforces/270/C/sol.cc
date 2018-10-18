#include <bits/stdc++.h>
using namespace std;

#ifdef DEBUG
    #define dbg(...) fprintf(stderr, __VA_ARGS__)
#else
    #define dbg(...)
#endif

const int K = 30;
int n, k, a, ans;
long long f4[K];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n;
    f4[0] = 1;
    for (int i = 1; i < K; ++i)
        f4[i] = 4LL * f4[i-1];
    for (int i = 0; i < n; ++i) {
        cin >> k >> a;
        int v = upper_bound(f4, f4+K, a-1) - f4;
        ans = max(ans, k+max(1, v));
    }
    cout << ans << '\n';

    return 0;
}
