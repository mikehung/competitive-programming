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
        int n, x;
        cin >> n >> x;
        vector<int> a(n);
        for (auto &it: a) cin >> it;
        ll sum = 0, zero = true, has_zero = false;
        for (int i = 0; i < n; ++i) {
            sum += x-a[i];
            if (x-a[i] != 0) zero = false;
            if (x-a[i] == 0) has_zero = true;
        }
        if (sum == 0) {
            cout << (zero ? 0 : 1) << '\n';
        } else {
            cout << (has_zero ? 1 : 2) << '\n';
        }
    }
    return 0;
}
