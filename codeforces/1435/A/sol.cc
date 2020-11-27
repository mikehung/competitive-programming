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
        for (int i = 0; i < n; i += 2) {
            int a, b;
            cin >> a >> b;
            cout << -b << ' ' << a << ' ';
        }
        cout << '\n';
    }
    return 0;
}
