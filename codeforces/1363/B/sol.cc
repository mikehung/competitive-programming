#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int tt;
    cin >> tt;
    while (tt--) {
        string s;
        cin >> s;
        int n = s.size();
        vector<int> pre(n+1);
        for (int i = 0; i < n; ++i) {
            pre[i+1] = pre[i] + int(s[i] == '1');
        }
        int an = n+11;
        for (int i = 0; i <= n; ++i) {
            an = min(an, pre[i] + (n - i - (pre[n] - pre[i])));
            an = min(an, i - pre[i] + pre[n] - pre[i]);
        }
        cout << an << '\n';
    }
    return 0;
}
