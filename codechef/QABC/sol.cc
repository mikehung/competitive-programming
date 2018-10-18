#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t, n;
    cin >> t;
    while (t--) {
        cin >> n;
        vector<int> a(n), b(n);
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
        }
        for (int i = 0; i < n; ++i) {
            cin >> b[i];
            b[i] -= a[i];
        }
        for (int i = 0; i < n-2; ++i) {
            if (b[i] < 0) {
                break;
            }
            b[i+2] -= 3 * b[i];
            b[i+1] -= 2 * b[i];
            b[i] = 0;
        }
        bool flag = true;
        for (int i = 0; i < n; ++i) {
            if (b[i]) flag = false;
        }
        if (flag) cout << "TAK\n";
        else cout << "NIE\n";
    }
    return 0;
}
