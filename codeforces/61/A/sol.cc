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
    string s, t;
    cin >> s >> t;
    for (int i = 0; i < (int) s.size(); ++i) {
        if (s[i] != t[i])
            cout << 1;
        else
            cout << 0;
    }
    cout << '\n';

    return 0;
}
