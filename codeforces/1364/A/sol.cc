#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--) {
        int n, x, all = 0;
        cin >> n >> x;
        vector<int> a(n);
        for (auto &it: a) {
            cin >> it;
            all += it;
        }
        int n1 = -1, n2 = -1;
        for (int i = 0; i < n; ++i) {
            if (a[i] % x != 0) {
                n1 = i;
                break;
            }
        }
        for (int i = n-1; i >= 0; --i) {
            if (a[i] % x != 0) {
                n2 = i;
                break;
            }
        }
        if (all % x != 0) {
            cout << n << '\n';
        } else if (n1 == -1 && n2 == -1) {
            cout << -1 << '\n';
        } else {
            cout << max(n-1-n1, n2) << '\n';
        }
    }
    return 0;
}
