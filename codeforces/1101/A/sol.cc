#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int q;
    cin >> q;
    while (q--) {
        int l, r, d;
        cin >> l >> r >> d;
        if (1.0*l/d > 1) {
            cout << d << '\n';
        } else {
            int k = r / d;
            cout << (k+1) * d << '\n';
        }
    }
    return 0;
}
