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
    if (n & 1) {
        cout << 9 << ' ' << n-9 << '\n';
    } else {
        cout << 4 << ' ' << n-4 << '\n';
    }

    return 0;
}
