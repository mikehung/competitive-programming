#include <bits/stdc++.h>
using namespace std;

#ifdef DEBUG
    #define dbg(...) fprintf(stderr, __VA_ARGS__)
#else
    #define dbg(...)
#endif

string rm_leading_zero(const string &s)
{
    if (s.empty()) return "";
    int i;
    for (i = 0; i < (int) s.size(); ++i) {
        if (s[i] != '0')
            break;
    }
    if (i == s.size())
        return "0";
    return s.substr(i);
}

string rm_one_two(const string &s, int one, int two)
{
    string t;
    for (int i = s.size() - 1; i >= 0; --i) {
        if (one && (s[i]-'0') % 3 == 1) {
            one--;
            continue;
        } else if (two && (s[i]-'0') % 3 == 2) {
            two--;
            continue;
        }
        t += s[i];
    }
    if (one || two)
        return "";
    reverse(t.begin(), t.end());
    return rm_leading_zero(t);
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    string s, ans;
    cin >> s;
    int val = 0;
    for (int i = 0; i < (int) s.size(); ++i) {
        val += (s[i] - '0') % 3;
    }
    val %= 3;
    if (val == 0) {
        ans = rm_leading_zero(s);
    } else {
        string s1, s2;
        if (val == 1) {
            s1 = rm_one_two(s, 1, 0);
            s2 = rm_one_two(s, 0, 2);
        } else {
            s1 = rm_one_two(s, 2, 0);
            s2 = rm_one_two(s, 0, 1);
        }
        if (s1.size() > s2.size())
            ans = s1;
        else
            ans = s2;
    }
    if (ans.empty()) {
        puts("-1");
    } else {
        cout << ans << '\n';
    }
    return 0;
}
