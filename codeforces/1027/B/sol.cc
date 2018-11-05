#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    long long n, q, x, y;
    cin >> n >> q;
    while (q--) {
        long long ans = 0;
        cin >> x >> y;
        if (n & 1) {
            if ((x + y) & 1)
                ans += (1LL * n * n + 1) / 2;
            ans += ((x + 1) / 2 - 1) * n;
            if (!(x & 1))
                ans += ((x + y) & 1) ? n / 2 : (n + 1) / 2;
            ans += (y + 1) / 2;
        } else {
            if ((x + y) & 1)
                ans += 1LL * n * n / 2;
            ans += (n / 2) * (x - 1) + (y + 1) / 2;
        }
        cout << ans << '\n';
    }
    return 0;
}
