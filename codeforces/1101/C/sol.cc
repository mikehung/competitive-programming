#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--) {
        int n, l, r, idx;
        cin >> n;
        vector<tuple<int, int, int>> v(n);
        vector<int> ans(n, 2);
        for (int i = 0; i < n; ++i) {
            cin >> l >> r;
            v[i] = make_tuple(l, r, i);
        }
        bool ok = false;
        int end;
        sort(v.begin(), v.end());
        for (int i = 0; i < n; ++i) {
            tie(l, r, idx) = v[i];
            if (i == 0) {
                end = r;
                ans[idx] = 1;
            } else if (end < l) {
                ok = true;
                break;
            } else {
                end = max(end, r);
                ans[idx] = 1;
            }
        }
        if (!ok) {
            cout << -1 << '\n';
        } else {
            for (auto &x: ans) {
                cout << x << ' ';
            }
            cout << '\n';
        }
    }
    return 0;
}
