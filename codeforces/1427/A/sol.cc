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
        int nonzero = 0, sum = 0;
        vector<int> a(n);
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
            if (a[i] != 0) nonzero++;
            sum += a[i];
        }
        if (sum == 0) {
            cout << "NO\n";
        } else {
            cout << "YES\n";
            if (sum < 0) {
                sort(a.begin(), a.end());
            } else {
                sort(a.rbegin(), a.rend());
            }
            for (auto x: a) cout << x << ' ';
            cout << '\n';
        }
    }
    return 0;
}
