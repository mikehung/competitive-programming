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
        int l, r;
        cin >> l >> r;
        cout << (r < 2*l ? "YES" : "NO") << '\n';
    }
    return 0;
}
