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
        int n, m;
        cin >> n >> m;
        map<int, vector<int>> mp;
        int first;
        for (int i = 0; i < n; ++i) {
            vector<int> a(m);
            for (auto &it: a) cin >> it;
            mp[a[0]] = a;
            if (i == 0) first = a[0];
        }

        vector<int> b(n), c(n);
        for (int i = 0; i < m; ++i) {
            bool ok = false;
            for (auto &it: c) {
                cin >> it;
                if (it == first) ok = true;
            }
            if (ok) b = c;
        }

        for (int i = 0; i < n; ++i) {
            for (auto x: mp[b[i]]) {
                cout << x << ' ';
            }
            cout << '\n';
        }
    }
    return 0;
}
