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
        vector<int> a(2*n+11);
        for (int i = 0; i < n; ++i) {
            int x;
            cin >> x;
            a[x]++;
        }

        int an = 0;
        for (int i = 2; i <= 2*n; ++i) {
            int cur = 0;
            for (int j = 1; j <= i-j; ++j) {
                if (j == i-j) {
                    cur += a[j]/2;
                } else {
                    cur += min(a[j], a[i-j]);
                }
            }
            an = max(an, cur);
        }
        cout << an << '\n';
    }
    return 0;
}
