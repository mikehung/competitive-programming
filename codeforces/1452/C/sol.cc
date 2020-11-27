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
        int n = s.size(), an = 0, c1 = 0, c2 = 0;
        for (int i = 0; i < n; ++i) {
            if (s[i] == '[') {
                ++c1;
            } else if (s[i] == ']') {
                if (c1 > 0) {
                    --c1;
                    ++an;
                }
            } else if (s[i] == '(') {
                ++c2;
            } else {
                if (c2 > 0) {
                    --c2;
                    ++an;
                }
            }
        }
        cout << an << '\n';
    }

    return 0;
}
