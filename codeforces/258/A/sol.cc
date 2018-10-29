#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    string s, t;
    cin >> s;
    bool first = true;
    for (int i = 0; i < (int) s.size(); ++i) {
        if (first && s[i] == '0') {
            first = false;
            continue;
        }
        t += s[i];
    }
    if (t.size() == s.size()) {
        t = t.substr(0, t.size()-1);
    }
    cout << t << '\n';
    return 0;
}
