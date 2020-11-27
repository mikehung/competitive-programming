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
        bool ok = false;
        set<int> se;
        for (int i = 0; i < n; ++i) {
            int x;
            cin >> x;
            if (se.count(x)) {
                ok = true;
            }
            se.insert(x);
        }
        cout << (ok ? "YES" : "NO") << '\n';
    }

    return 0;
}
