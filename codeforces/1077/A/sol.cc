#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--) {
        long long a, b, k, ans = 0;
        cin >> a >> b >> k;
        ans = (a - b) * (k / 2);
        if (k & 1) {
            ans += a;
        }
        cout << ans << '\n';
    }
    return 0;
}
