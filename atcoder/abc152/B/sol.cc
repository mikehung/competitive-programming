#include <bits/stdc++.h>

using namespace std;

string f(const string &s, const string &t)
{
    // cout << s << ' ' << t << endl;
    int s1 = s.size(), s2 = t.size();
    for (int i = 0; i < min(s1, s2); ++i) {
        if (s[i] != t[i]) {
            if (s[i] < t[i]) return s;
            else return t;
        }
    }
    if (s1 < s2) return s;
    return t;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int a, b;
    cin >> a >> b;
    string s = string(b, a+'0'), t = string(a, b+'0');
    cout << f(s, t) << endl;
    return 0;
}
