#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--) {
        int n;
        string s;
        cin >> n >> s;
        int l = -1, r = -1;
        for (int i = 0; i < n; ++i) {
            if (s[i] == 'R') {
                r = i;
                break;
            }
        }
        for (int i = n-1; i >= 0; --i) {
            if (s[i] == 'L') {
                l = i;
                break;
            }
        }
        if (l == -1 || r == -1) {
            cout << (n+2)/3 << '\n';
            continue;
        }
        if (s[0] == 'L') {
            s = s.substr(r) + s.substr(0, r);
        } else if (s[n-1] == 'R') {
            s = s.substr(l+1) + s.substr(0, l+1);
        }
        assert(s[0] == 'R');
        assert(s[n-1] == 'L');
        int an = 0, i = 0;
        while (i < n) {
            int l = 0, r = 0;
            while (i < n && s[i] == 'R') {
                ++r, ++i;
            }
            while (i < n && s[i] == 'L') {
                ++l, ++i;
            }
            int op = INT_MAX;
            if (r == 0) {
                op = (l+2)/3;
            } else if (l == 0) {
                op = (r+2)/3;
            } else {
                op = min(op, (l+1)/3 + (r+1)/3);
                if (r > 1) {
                    op = min(op, (l+1)/3 + r/3);
                }
                if (l > 1) {
                    op = min(op, l/3 + (r+1)/3);
                }
                if (r > 1 && l > 1) {
                    op = min(op, l/3 + r/3);
                }
            }
            an += op;
        }
        cout << an << endl;
    }
    return 0;
}
