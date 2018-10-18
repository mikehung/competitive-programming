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
    int n, a, f, i, ans;
    a = f = i = ans = 0;
    string s;
    cin >> n >> s;
    for (char ch : s) {
        if (ch == 'A') ++a;
        else if (ch == 'F') ++f;
        else ++i;
    }
    if (i == 0) cout << a << '\n';
    else if (i == 1) cout << 1 << '\n';
    else cout << 0 << '\n';
    return 0;
}
