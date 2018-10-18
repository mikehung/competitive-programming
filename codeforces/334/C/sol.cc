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
    long long n, x = 3;
    cin >> n;
    while (x <= n) {
        if (n % x != 0) {
            cout << n / x + 1 << '\n';
            return 0;
        }
        x *= 3;
    }
    cout << 1 << '\n';

    return 0;
}
