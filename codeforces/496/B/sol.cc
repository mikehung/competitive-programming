#include <bits/stdc++.h>

using namespace std;

string min_str(const string &s1, const string &s2)
{
    int n1 = s1.size(), n2 = s2.size();
    if (n1 < n2)
        return s1;
    if (n2 < n1)
        return s2;
    for (int i = 0; i < n1; ++i)
        if (s1[i] != s2[i])
            return s1[i] < s2[i] ? s1 : s2;
    return s1;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    string s, ans;
    cin >> n >> s;
    ans = s;
    for (int i = 0; i < n; ++i) {
        string t;
        int diff = (10 - (s[i] - '0')) % 10;
        for (int j = 0; j < n; ++j) {
            t += (s[(i+j)%n] - '0' + diff) % 10 + '0';
        }
        int cnt = 0;
        while (cnt < n && t[n-cnt-1] == '0') ++cnt;
        t = t.substr(n-cnt) + t.substr(0, n-cnt);
        assert((int) t.size() == n);
        ans = min_str(ans, t);
    }
    cout << ans << '\n';

    return 0;
}
