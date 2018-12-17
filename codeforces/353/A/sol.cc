#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, up = 0, down = 0;
    bool oe = false;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        int a, b;
        cin >> a >> b;
        up += a;
        down += b;
        if ((a % 2) ^ (b % 2))
            oe = true;
    }
    if ((up % 2) == 0 && (down % 2) == 0) {
        cout << 0 << '\n';
    } else if (n > 1 && oe && (up % 2) && (down % 2)) {
        cout << 1 << '\n';
    } else {
        cout << -1 << '\n';
    }
    return 0;
}
