#include <bits/stdc++.h>

using namespace std;

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
        bool ok = true;
        if (n == 2 && s[0]-'0' >= s[1]-'0') ok = false;
        if (ok) {
            cout << "YES\n2\n";
            cout << s.substr(0, 1) << ' ' << s.substr(1) << '\n';
        } else {
            cout << "NO\n";
        }
    }
    return 0;
}
