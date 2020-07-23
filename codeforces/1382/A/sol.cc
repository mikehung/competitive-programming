#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<int> a(n);
        set<int> b;
        for (auto &it: a) cin >> it;
        for (int i = 0; i < m; ++i) {
            int x;
            cin >> x;
            b.insert(x);
        }
        int an = -1;
        for (int i = 0; i < n; ++i) {
            if (b.count(a[i])) {
                an = a[i];
                break;
            }
        }
        if (an == -1) {
            cout << "NO\n";
        } else {
            cout << "YES\n1 " << an << '\n';
        }
    }
    return 0;
}
