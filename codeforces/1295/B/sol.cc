#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--) {
        int n, x;
        cin >> n >> x;
        string s;
        cin >> s;
        vector<int> pre(n+1);
        for (int i = 0; i < n; ++i) {
            pre[i+1] = pre[i] + (s[i] == '0' ? 1 : -1);
        }
        int k = pre[n], an = 0;
        if (pre[0] == x) an++;

        if (k == 0) {
            for (int i = 1; i <= n; ++i) {
                if (pre[i] == x) an = -1;
            }
        } else {
            for (int i = 1; i <= n; ++i) {
                if ((x-pre[i]) % k == 0) {
                    int v = (x-pre[i]) / k;
                    if (v >= 0) ++an;
                }
            }
        }
        cout << an << '\n';
    }
    return 0;
}
