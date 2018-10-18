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
    int n;
    cin >> n;
    if (n & 1)
        cout << -1 << '\n';
    else {
        for (int i = 1; i <= n; i += 2) {
            cout << i+1 << ' ' << i << ' ';
        }
        cout << '\n';
    }

    return 0;
}
