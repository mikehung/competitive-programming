#include <bits/stdc++.h>

using namespace std;

int a;
string sa, sb;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> a >> sb;
    while (true) {
        sa = "";
        for (auto ch: to_string(++a)) {
            if (ch == '4' || ch == '7')
                sa += ch;
        }
        if (sa == sb) {
            cout << a << '\n';
            break;
        }
    }
    return 0;
}
