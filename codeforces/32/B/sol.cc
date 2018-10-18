#include <bits/stdc++.h>
using namespace std;

#ifdef DEBUG
    #define dbg(...) fprintf(stderr, __VA_ARGS__)
#else
    #define dbg(...)
#endif

int main()
{
    string s, t;
    cin >> s;
    int i = 0, n = s.size();
    while (i < n) {
        if (s[i] == '.') {
            t += '0';
            i++;
        } else if (s[i+1] == '.') {
            t += '1';
            i += 2;
        } else {
            t += '2';
            i += 2;
        }
    }
    cout << t << '\n';

    return 0;
}
