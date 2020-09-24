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
        vector<int> b(a);
        sort(b.begin(), b.end());
        bool ok = true;
        for (int i = 0; i < n; ++i) if (a[i] != b[i]) {
            if (a[i] % b[0] != 0) {
                ok = false;
            }
        }
        cout << (ok ? "YES" : "NO") << '\n';
    }
    return 0;
}
