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
        int n, k;
        cin >> n >> k;
        vector<int> a(n);
        for (auto &it: a) cin >> it;
        if (k == 1) {
            bool eq = true;
            for (int i = 1; i < n; ++i) if (a[i] != a[0]) eq = false;
            cout << (eq ? 1 : -1) << '\n';
        } else {
            a.erase(unique(a.begin(), a.end()), a.end());
            int sz = a.size();
            sz = max(0, sz-k);
            cout << 1 + (sz+k-2)/(k-1) << '\n';
        }
    }
    return 0;
}
