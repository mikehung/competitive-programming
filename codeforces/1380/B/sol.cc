#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--) {
        string str;
        cin >> str;
        int n = str.size(), r = 0, s = 0, p = 0;
        for (int i = 0; i < n; ++i) {
            if (str[i] == 'R') r++;
            else if (str[i] == 'S') s++;
            else p++;
        }
        string an;
        if (r >= s && r >= p) {
            an = string(n, 'P');
        } else if (s >= r && s >= p) {
            an = string(n, 'R');
        } else {
            an = string(n, 'S');
        }
        cout << an << '\n';
    }
    return 0;
}
