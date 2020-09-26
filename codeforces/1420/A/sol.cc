#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> a(n);
        for (auto &it: a) cin >> it;

        bool ok = false;
        for (int i = 1; i < n; ++i) {
            if (a[i-1] <= a[i]) ok = true;
        }
        cout << (ok ? "YES" : "NO") << '\n';
    }
    return 0;
}
