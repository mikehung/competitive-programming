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
        int n, x;
        cin >> n >> x;
        if (n < 3) {
            cout << 1 << '\n';
        } else {
            cout << (n-3)/x+2 << '\n';
        }
    }
    return 0;
}
