#include <bits/stdc++.h>
using namespace std;

#ifdef DEBUG
    #define dbg(...) fprintf(stderr, __VA_ARGS__)
#else
    #define dbg(...)
#endif

void change(string &s, char lo, char hi, char ch)
{
    for (int i = 0; i < (int) s.size(); ++i) {
        if (lo <= s[i] && s[i] <= hi) {
            s[i] = ch;
            break;
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int T, u, l, d;
    string s;
    cin >> T;
    while (T--) {
        cin >> s;
        u = l = d = 0;
        for (char ch : s) {
            if ('A' <= ch && ch <= 'Z')
                ++u;
            if ('a' <= ch && ch <= 'z')
                ++l;
            if ('0' <= ch && ch <= '9')
                ++d;
        }
        if (!u && l && d) {
            if (l > 1)
                change(s, 'a', 'z', 'A');
            else
                change(s, '0', '9', 'A');
        } else if (u && !l && d) {
            if (u > 1)
                change(s, 'A', 'Z', 'a');
            else
                change(s, '0', '9', 'a');
        } else if (u && l && !d) {
            if (u > 1)
                change(s, 'A', 'Z', '0');
            else
                change(s, 'a', 'z', '0');
        } else if (!u && !l) {
            s[0] = 'A', s[1] = 'a';
        } else if (!u && !d) {
            s[0] = 'A', s[1] = '0';
        } else if (!l && !d) {
            s[0] = 'a', s[1] = '0';
        }
        cout << s << '\n';
    }

    return 0;
}
