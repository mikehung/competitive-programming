#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    vector<int> h(n+1);
    for (int i = 1; i <= n; ++i) cin >> h[i];
    int ans = 0, hh = h[0];
    for (int i = 1; i <= n; ++i) {
        if (h[i] >= h[i-1]) {
            if (i == n) ans += h[i] - hh;
            continue;
        }
        ans += h[i-1] - hh;
        hh = h[i];
    }
    cout << ans << endl;
    return 0;
}
