#include <bits/stdc++.h>
using namespace std;

#ifdef DEBUG
    #define dbg(...) fprintf(stderr, __VA_ARGS__)
#else
    #define dbg(...)
#endif

int n, a[8];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n;
    for (int i = 1; i < 8; ++i)
        cin >> a[i];

    while (true) {
        for (int i = 1; i < 8; ++i) {
            n -= a[i];
            if (n <= 0) {
                cout << i << '\n';
                return 0;
            }
        }
    }

    return 0;
}
