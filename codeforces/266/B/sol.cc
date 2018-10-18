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
    int n, t;
    string s;
    cin >> n >> t >> s;
    while (t--) {
        string u;
        for (int i = 0; i < n; ++i) {
            if (i != n-1 && s[i] == 'B' && s[i+1] == 'G') {
                u += "GB";
                ++i;
            } else {
                u += s[i];
            }
        }
        s = u;
    }
    cout << s << '\n';

    return 0;
}
