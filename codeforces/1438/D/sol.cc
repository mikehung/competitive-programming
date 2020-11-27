#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    vector<int> a(n);
    for (auto &it: a) cin >> it;
    if (n % 2 == 0) {
        for (int i = 1; i+1 < n; i += 2) {
            int v = a[0] ^ a[i] ^ a[i+1];
            a[0] = a[i] = a[i+1] = v;
        }

        if (a[0] != a[n-1]) {
            cout << "NO\n";
        } else {
            cout << "YES\n" << n-2 << '\n';
            for (int i = 1; i+1 < n; i += 2) {
                cout << 1 << ' ' << i+1 << ' ' << i+2 << '\n';
            }
            for (int i = 1; i+1 < n; i += 2) {
                cout << 1 << ' ' << i+1 << ' ' << i+2 << '\n';
            }
        }
    } else {
        cout << "YES\n" << n-1 << '\n';
        for (int i = 1; i+1 < n; i += 2) {
            cout << 1 << ' ' << i+1 << ' ' << i+2 << '\n';
        }
        for (int i = 1; i+1 < n; i += 2) {
            cout << 1 << ' ' << i+1 << ' ' << i+2 << '\n';
        }
    }

    return 0;
}
