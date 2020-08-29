#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    vector<vector<ll>> a(n, vector<ll>(n));
    for (int i = 0; i < n; i += 2) {
        for (int j = 0; j < n; ++j) {
            a[i][j] = 1ll << (i+1+j);
        }
    }
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cout << a[i][j] << ' ';
        }
        cout << '\n';
    }
    cout << endl;

    int t;
    cin >> t;
    while (t--) {
        ll q;
        cin >> q;
        int i = 0, j = 0;
        while (true) {
            cout << i+1 << ' ' << j+1 << '\n';
            if (i == n-1 && j == n-1) break;
            if (i == n-1) {
                ++j;
            } else if (j == n-1) {
                ++i;
            } else if (i % 2 == 0) {
                int k = i+1+j+1;
                if ((q >> k) & 1) {
                    ++j;
                } else {
                    ++i;
                }
            } else {
                int k = i+2+j;
                if ((q >> k) & 1) {
                    ++i;
                } else {
                    ++j;
                }
            }
        }
        cout << endl;
    }
    return 0;
}
