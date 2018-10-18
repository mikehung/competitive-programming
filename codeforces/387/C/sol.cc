#include <bits/stdc++.h>
using namespace std;

#ifdef DEBUG
    #define dbg(...) fprintf(stderr, __VA_ARGS__)
#else
    #define dbg(...)
#endif

bool can_concat(string &a, string &b)
{
    if (a.size() > b.size())
        return true;
    if (b.size() > a.size())
        return false;
    int i = 0;
    while (i < a.size() && a[i] == b[i]) ++i;
    return i == a.size() || a[i]-'0' > b[i]-'0';
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    string s, t;
    vector<string> split;
    cin >> s;
    int n = s.size();
    for (int i = 0; i < n; ++i) {
        t += s[i];
        if (i == n-1 || s[i+1] != '0') {
            split.push_back(t);
            t = "";
        }
    }
    int ans = split.size(), cnt = 1;
    string str = split[0];
    for (int i = 1; i < split.size(); ++i) {
        if (can_concat(str, split[i])) {
            ++cnt;
        } else {
            ans -= cnt;
            cnt = 1;
        }
        str += split[i];
    }
    cout << ans << '\n';

    return 0;
}
