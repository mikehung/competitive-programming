#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int tt;
    cin >> tt;
    while (tt--) {
        int n, t;
        cin >> n >> t;
        vector<int> a(n), an(n);
        for (auto &it: a) cin >> it;

        int mid = -1, grp = 0, lo;
        if (t % 2 == 0) {
            mid = t/2;
            lo = mid-1;
        } else {
            lo = t/2;
        }
        for (int i = 0; i < n; ++i) {
            if (a[i] == mid) {
                cout << grp << ' ';
                grp = 1-grp;
            } else if (a[i] <= lo) {
                cout << 0 << ' ';
            } else {
                cout << 1 << ' ';
            }
        }
        cout << '\n';
    }
    return 0;
}
