#include <bits/stdc++.h>

using namespace std;

void solve()
{
    string str, an;
    cin >> str;
    int sz = str.size(), pre = 0, cur;
    for (int i = 0; i < sz; ++i) {
        cur = str[i]-'0';
        if (pre > cur) {
            an += string(pre-cur, ')');
        } else if (pre < cur) {
            an += string(cur-pre, '(');
        }
        an += str[i];
        pre = cur;
    }
    cur = 0;
    if (pre > cur) {
        an += string(pre-cur, ')');
    } else if (pre < cur) {
        an += string(cur-pre, '(');
    }

    cout << an << '\n';
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout << fixed << setprecision(6);
    int T;
    cin >> T;
    for (int t = 1; t <= T; ++t) {
        cout << "Case #" << t << ": ";
        solve();
    }
    return 0;
}
