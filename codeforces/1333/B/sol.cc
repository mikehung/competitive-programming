#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> a(n), b(n);
        for (auto &it: a) cin >> it;
        for (auto &it: b) cin >> it;

        bool ok = true, pos = false, neg = false;
        for (int i = 0; i < n; ++i) {
            if (a[i] > b[i] && !neg) {
                ok = false;
            } else if (a[i] < b[i] && !pos) {
                ok = false;
            }
            if (a[i] > 0) pos = true;
            else if (a[i] < 0) neg = true;
        }

        cout << (ok ? "YES" : "NO") << '\n';
    }
    return 0;
}
