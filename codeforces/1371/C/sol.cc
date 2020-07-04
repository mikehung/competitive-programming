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
        ll a, b, n, m;
        cin >> a >> b >> n >> m;
        if (min(a, b) >= m && a+b >= n+m) {
            cout << "Yes\n";
        } else {
            cout << "No\n";
        }
    }

    return 0;
}
