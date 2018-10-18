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
    int n, a = 1, b, c;
    cin >> n;
    n--;
    if (n & 1) {
        b = c = n / 2;
        c++;
        if ((b % 3) == 0) {
            a = 2;
            b--;
        }
        if ((c % 3) == 0) {
            a = 2;
            c--;
        }
    } else {
        b = c = n / 2;
        if ((b % 3) == 0) {
            b++;
            c--;
        }
    }
    cout << a << ' ' << b << ' ' << c << '\n';

    return 0;
}
