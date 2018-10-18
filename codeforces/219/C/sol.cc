#include <bits/stdc++.h>
using namespace std;

#ifdef DEBUG
    #define dbg(...) fprintf(stderr, __VA_ARGS__)
#else
    #define dbg(...)
#endif

int n, k;
string s;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> k >> s;
    if (k == 2) {
        string t, u;
        for (int i = 0; i < n; ++i) {
            t += i&1 ? 'A' : 'B';
            u += i&1 ? 'B' : 'A';
        }
        int ct = 0, cu = 0;
        for (int i = 0; i < n; ++i) {
            if (s[i] != t[i])
                ++ct;
            if (s[i] != u[i])
                ++cu;
        }
        if (ct < cu) {
            cout << ct << '\n' << t << '\n';
        } else {
            cout << cu << '\n' << u << '\n';
        }
    } else {
        string abc = "ABC";
        int cnt = 0;
        for (int i = 1; i < n; ++i) {
            if (s[i] == s[i-1]) {
                ++cnt;
                for (char ch : abc) if (ch != s[i-1] && (i == n-1 || ch != s[i+1])) {
                    s[i] = ch;
                    break;
                }
            }
        }
        cout << cnt << '\n' << s << '\n';
    }
    return 0;
}
