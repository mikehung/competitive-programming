#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    string s;
    cin >> n >> s;
    int l = n/2, r = n/2;
    for (int i = 0; i < n; ++i) {
        if (s[i] == '(') --l;
        if (s[i] == ')') --r;
    }
    if (l < 0 || r < 0) {
        cout << ":(\n";
        return 0;
    }
    for (int i = 0; i < n; ++i) if (s[i] == '?') {
        if (l > 0) s[i] = '(', --l;
        else s[i] = ')', --r;
    }
    int v = 0;
    for (int i = 0; i < n; ++i) {
        if (s[i] == '(') v++;
        else v--;
        if (v < 0 || (i != n-1 && v == 0)) {
            cout << ":(\n";
            return 0;
        }
    }
    if (v != 0) {
        cout << ":(\n";
    } else {
        cout << s << '\n';
    }
    return 0;
}
