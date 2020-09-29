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
        int mn = 0;
        vector<int> a(n);
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
            if (a[mn] > a[i]) {
                mn = i;
            }
        }
        ll an = 0;
        for (int i = 0; i < n; ++i) if (i != mn) {
            an += (k-a[i])/a[mn];
        }
        cout << an << '\n';
    }
    return 0;
}
