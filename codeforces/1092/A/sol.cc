#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t, n, k;
    cin >> t;
    while (t--) {
        cin >> n >> k;
        string ans;
        for (int i = 0; i < n; ++i) {
            ans += 'a' + i%k;
        }
        cout << ans << '\n';
    }
    return 0;
}
