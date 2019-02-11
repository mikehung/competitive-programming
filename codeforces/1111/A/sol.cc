#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    string s, t;
    cin >> s >> t;
    bool ok = true;
    set<char> vowels = {'a', 'e', 'i', 'o', 'u'};
    if (s.size() != t.size()) {
        ok = false;
    }
    for (int i = 0; i < (int) s.size(); ++i) {
        if (vowels.count(s[i]) != vowels.count(t[i]))
            ok = false;
    }
    cout << (ok ? "Yes" : "No") << endl;
    return 0;
}
