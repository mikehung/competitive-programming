#include <bits/stdc++.h>

using namespace std;

int T, n, l, r;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> T;
    while (T--) {
        cin >> n;
        vector<int> ans(n, 2);
        vector<pair<pair<int, int>, int>> v;
        for (int i = 0; i < n; ++i) {
            cin >> l >> r;
            v.push_back(make_pair(make_pair(l, r), i));
        }
        sort(v.begin(), v.end());
        int ok = -1;
        for (int i = 0; i < n-1; ++i) {
            ans[v[i].second] = 1;
            if (v[i].first.second < v[i+1].first.first) {
                ok = i;
                break;
            }
        }
        if (ok == -1) {
            cout << -1 << '\n';
        } else {
            for (int i = 0; i < n; ++i) {
                cout << ans[i] << ' ';
            }
            cout << '\n';
        }
    }
    return 0;
}
