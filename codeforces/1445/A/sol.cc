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
        int n, x;
        cin >> n >> x;
        vector<int> a(n), b(n);
        for (auto &it: a) cin >> it;
        for (auto &it: b) cin >> it;
        sort(a.begin(), a.end());
        sort(b.rbegin(), b.rend());
        bool ok = true;
        for (int i = 0; i < n; ++i) if (a[i] + b[i] > x) ok = false;
        cout << (ok ? "Yes" : "No") << '\n';
    }
    return 0;
}
