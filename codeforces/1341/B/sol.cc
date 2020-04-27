#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int tt;
    cin >> tt;
    while (tt--) {
        int n, k;
        cin >> n >> k;
        vector<int> a(n), peak(n);
        for (auto &it: a) cin >> it;
        for (int i = 1; i < n-1; ++i) {
            if (a[i] > a[i-1] && a[i] > a[i+1]) peak[i] = 1;
        }
        for (int i = 1; i < n; ++i) {
            peak[i] += peak[i-1];
        }
        int best = peak[k-2], besti = 0;
        for (int i = 1; i+k-1 < n; ++i) {
            int cur = peak[i+k-2] - peak[i];
            if (cur > best) {
                best = cur;
                besti = i;
            }
        }
        cout << best+1 << ' ' << besti+1 << '\n';
    }
    return 0;
}
