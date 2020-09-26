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
        int n;
        string s;
        cin >> n >> s;
        int cnt = 0;
        vector<int> an(n), one, zero;
        for (int i = 0; i < n; ++i) {
            if (s[i] == '1') {
                if (zero.empty()) {
                    zero.push_back(++cnt);
                }
                one.push_back(zero.back());
                zero.pop_back();
                an[i] = one.back();
            } else {
                if (one.empty()) {
                    one.push_back(++cnt);
                }
                zero.push_back(one.back());
                one.pop_back();
                an[i] = zero.back();
            }
        }
        cout << cnt << '\n';
        for (auto x: an) cout << x << ' ';
        cout << '\n';
    }
    return 0;
}
