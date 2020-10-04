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
        vector<int> a(n), b(n), c(n);
        for (auto &it: a) cin >> it;
        for (auto &it: b) cin >> it;
        for (auto &it: c) cin >> it;
        for (int i = 0; i < n; ++i) {
            int j = (i+1)%n, k = (i-1+n)%n;;
            if (b[i] != a[j] && b[i] != a[k]) a[i] = b[i];
            if (c[i] != a[j] && c[i] != a[k]) a[i] = c[i];
            cout << a[i] << ' ';
        }
        cout << endl;
    }
    return 0;
}
