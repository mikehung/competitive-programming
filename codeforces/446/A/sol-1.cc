#include <bits/stdc++.h>
using namespace std;

#ifdef DEBUG
    #define dbg(...) fprintf(stderr, __VA_ARGS__)
#else
    #define dbg(...)
#endif

const int MAX = (int) 1e5+5;
int n, a[MAX], cnt1[MAX], cnt2[MAX];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
    }
    a[n+1] = INT_MAX;
    cnt1[n] = 1;
    for (int i = n-1; i > 0; --i) {
        if (a[i] < a[i+1])
            cnt1[i] = cnt1[i+1] + 1;
        else
            cnt1[i] = 1;
    }
    cnt2[1] = 1;
    for (int i = 1; i <= n; ++i) {
        if (a[i] > a[i-1])
            cnt2[i] = cnt2[i-1] + 1;
        else
            cnt2[i] = 1;
    }
    // for (int i = 1; i <= n; ++i) cerr << cnt1[i] << ' '; cerr << '\n';
    int ans = 1;
    for (int i = 1; i < n; ++i) {
        int k = i + cnt1[i];
        int v = cnt1[i];
        if (k != n+1) {
            ++v;
            if (a[k-1] + 2 <= a[k+1])
                v += cnt1[k+1];
        }
        ans = max(ans, v);
    }
    for (int i = n; i > 1; --i) {
        int k = i - cnt2[i];
        int v = cnt2[i];
        if (k != 0) {
            ++v;
            if (a[k+1] - 2 >= a[k-1])
                v += cnt2[k-1];
        }
        ans = max(ans, v);
    }
    cout << ans << '\n';
    return 0;
}
