#include <bits/stdc++.h>

using namespace std;

int ans, mx, x, n;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> x;
        mx = max(x, mx);
        if (mx <= i) {
            ans++;
        }
    }
    cout << ans << endl;
    return 0;
}
