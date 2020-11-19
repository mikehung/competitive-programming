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
        ll a, b, an = 0;
        string s;
        cin >> a >> b >> s;
        ll n = s.size(), zero_cnt = 0;
        bool activate = false;
        for (int i = 0; i < n; ++i) {
            if (s[i] == '0') {
                zero_cnt++;
            } else {
                if (i == 0 || s[i-1] == '0') {
                    if (!activate) {
                        activate = true;
                        an += a;
                    } else {
                        an += min(a, b*zero_cnt);
                    }
                    zero_cnt = 0;
                }
            }
        }
        cout << an << '\n';
    }
    return 0;
}
