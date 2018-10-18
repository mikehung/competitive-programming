#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t, n;
    cin >> t;
    while (t--) {
        vector<int> a;
        cin >> n;
        for (int i = 0; i < n; ++i) {
            int x;
            cin >> x;
            a.push_back(x);
        }
        int ans = 0, i = 1, cur = a[0], nxt;
        while (i < n) {
            ++ans;
            nxt = cur;
            while (i < n && cur--) {
                nxt += a[i++];
            }
            cur = nxt;
        }
        cout << ans << '\n';
    }
    return 0;
}
