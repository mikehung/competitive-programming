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
        int n;
        cin >> n;
        vector<int> a(n);
        for (auto &it: a) cin >> it;
        sort(a.begin(), a.end());
        bool ok = true;
        for (int i = 0; i < n-1; ++i) {
            if (a[i+1]-a[i] > 1) ok = false;
        }
        cout << (ok ? "YES" : "NO") << '\n';
    }
    return 0;
}
