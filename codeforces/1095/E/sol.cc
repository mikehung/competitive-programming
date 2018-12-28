#include <bits/stdc++.h>

using namespace std;

const int MAX = (int) 1e6 + 5;
int n, ans;
map<int, int> m;
string s;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int c = 0;
    cin >> n >> s;
    for (int i = 0; i < n; ++i) {
        if (i)
            c += (s[i] == '(') ? 1 : -1;
        else
            c = (s[0] == '(') ? 1 : -1;
        ++m[c];
    }
    if (abs(c) != 2) {
        cout << 0 << '\n';
        return 0;
    }
    if (c == 2) {
        // ( => ): -2
        c = 0;
        for (int i = 0; i < n; ++i) {
            c += (s[i] == '(') ? 1 : -1;
            if (s[i] == '(' && c >= 2 && m.begin()->first >= 2) ++ans;
            if (c < 0) break;
            if (!--m[c]) m.erase(c);
        }
    } else {
        // ) => (: +2
        c = 0;
        for (int i = 0; i < n; ++i) {
            c += (s[i] == '(') ? 1 : -1;
            if (s[i] == ')' && m.begin()->first >= -2) ++ans;
            if (c < 0) break;
            if (!--m[c]) m.erase(c);
        }
    }
    cout << ans << '\n';
    return 0;
}
