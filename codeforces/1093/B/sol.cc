#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    string s;
    cin >> t;
    while (t--) {
        cin >> s;
        int diff = -1;
        for (int i = 1; i < s.size(); ++i) {
            if (s[i] != s[0]) {
                diff = i;
                break;
            }
        }
        if (diff == -1) {
            cout << -1 << '\n';
            continue;
        }
        swap(s[diff], s[s.size()-1]);
        cout << s << '\n';
    }
    return 0;
}
