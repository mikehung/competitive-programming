#include <bits/stdc++.h>

using namespace std;

int ans[200];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t, n;
    cin >> t;
    for (int i = 0; i <= 200; ++i) ans[i] = -1;
    for (int i = 3; i <= 3600; ++i) {
        for (int j = 1; j <= i-2; ++j) {
            if ((180 * j) % i == 0 && ans[(180*j)/i] == -1)
                ans[(180*j)/i] = i;
        }
    }
    while (t--) {
        cin >> n;
        cout << ans[n] << '\n';
    }
    return 0;
}
