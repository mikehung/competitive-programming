#include <bits/stdc++.h>
using namespace std;

#ifdef DEBUG
    #define dbg(...) fprintf(stderr, __VA_ARGS__)
#else
    #define dbg(...)
#endif

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, t, u = 0, c1, c2, c3;
    string s1, s2, s3, abc = "abc";
    cin >> n >> t >> s1 >> s2;
    t = n - t;
    for (int i = 0; i < n; ++i)
        if (s1[i] == s2[i])
            ++u;
    if (t > u) {
        c1 = c2 = t - u;
        c3 = u;
    } else {
        c1 = c2 = 0;
        c3 = t;
    }
    if (u + c1 + c2 > n) {
        cout << -1 << '\n';
        return 0;
    }
    for (int i = 0; i < n; ++i) {
        if (c3 && s1[i] == s2[i]) {
            s3 += s1[i];
            c3--;
        } else if (c1) {
            s3 += s1[i];
            c1--;
        } else if (c2) {
            s3 += s2[i];
            c2--;
        } else {
            for (char ch : abc) {
                if (ch != s1[i] && ch != s2[i]) {
                    s3 += ch;
                    break;
                }
            }
        }
    }
    cout << s3 << '\n';

    return 0;
}
