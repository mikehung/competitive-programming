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
        ll a, b, c, d;
        cin >> a >> b >> c >> d;
        cout << max(a+b, c+d) << '\n';
    }
    return 0;
}
