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
        int n, k;
        cin >> n >> k;
        string s;
        cin >> s;
        vector<int> pre(n+1);
        for (int i = 0; i < n; ++i) {
            pre[i+1] = pre[i] + int(s[i] == '1');
        }
        int an = 0;
        for (int i = 0; i < n; ++i) {
            if (s[i] == '0') {
                if (pre[min(n, i+k+1)] - pre[max(0, i-k)] == 0) {
                    an++;
                    i += k;
                }
            }
        }
        cout << an << '\n';
    }
    return 0;
}
