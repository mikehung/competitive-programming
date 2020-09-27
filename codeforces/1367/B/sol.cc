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
        vector<int> a(n);
        int e = 0, o = 0, mis = 0;
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
            if (a[i] % 2 == 1) {
                ++o;
                if (i % 2 == 0) mis++;
            } else {
                ++e;
                if (i % 2 == 1) mis++;
            }
        }
        int te = n/2, to = n/2;
        if (n % 2) {
            ++te;
        }
        if (e == te && o == to) {
            cout << mis/2 << '\n';
        } else {
            cout << -1 << '\n';
        }
    }
    return 0;
}
