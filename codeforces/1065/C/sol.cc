#include <bits/stdc++.h>
using namespace std;

#ifdef DEBUG
    #define dbg(...) fprintf(stderr, __VA_ARGS__)
#else
    #define dbg(...)
#endif

const int MAX = 2*1e5+123;
int n, k, h[MAX], mn = MAX;
long long cnt[MAX], Slice[MAX], ans;

int solve(int i)
{
    int lo = 0, hi = i;
    while (lo < hi) {
        int mid = lo + (hi - lo) / 2;
        if (Slice[mid] - Slice[i] <= k) {
            hi = mid;
        } else {
            lo = mid+1;
        }
    }
    return lo;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> k;
    for (int i = 0; i < n; ++i) {
        cin >> h[i];
        if (mn > h[i])
            mn = h[i];
    }
    for (int i = 0; i < n; ++i) {
        ++cnt[h[i]-mn];
        // cerr << h[i]-mn << ' ';
    }
    // cerr << "\nxxx\n";
    for (int i = MAX-2; i >= 0; --i) {
        cnt[i] += cnt[i+1];
    }
    for (int i = MAX-2; i >= 0; --i) {
        Slice[i] = Slice[i+1] + cnt[i+1];
    }
    // for (int i = 0; i < 10; ++i)
    //     cerr << cnt[i] << ' ';
    // cerr << '\n';
    // for (int i = 0; i < 10; ++i)
    //     cerr << Slice[i] << ' ';
    // cerr << '\n';
    int i = MAX-1;
    while (i >= 0 && !Slice[i]) --i;
    i++;
    while (i) {
        // int j = i;
        i = solve(i);
        // cerr << " i: " << i << ' ' << Slice[i] - Slice[j];
        ++ans;
    }
    cout << ans << '\n';

    return 0;
}
