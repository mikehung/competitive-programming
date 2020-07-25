#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int tt;
    cin >> tt;
    while (tt--) {
        int n;
        cin >> n;
        vector<int> a(n);
        for (auto &it: a) cin >> it;
        int mx = 1;
        for (int i = 0; i < n; ++i) {
            mx = max(mx, a[i]);
        }
        string pre(mx, 'a');
        cout << pre << '\n';
        for (int i = 0; i < n; ++i) {
            string cur;
            for (int j = 0; j < mx; ++j) {
                if (j < a[i]) {
                    cur += pre[j];
                } else {
                    cur += pre[j] == 'a' ? 'b' : 'a';
                }
            }
            cout << cur << '\n';
            pre = cur;
        }
    }
    return 0;
}
