#include <bits/stdc++.h>
using namespace std;

#ifdef DEBUG
    #define dbg(...) fprintf(stderr, __VA_ARGS__)
#else
    #define dbg(...)
#endif

const int N = 10, n = 3;
int a[N][N], b[N][N];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int x;
    for (int r = 1; r <= n; ++r) {
        for (int c = 1; c <= n; ++c) {
            cin >> x;
            a[r][c] += x;
            a[r-1][c] += x;
            a[r+1][c] += x;
            a[r][c-1] += x;
            a[r][c+1] += x;
        }
    }
    for (int r = 1; r <= n; ++r) {
        for (int c = 1; c <= n; ++c) {
            if (a[r][c] & 1)
                cout << 0;
            else
                cout << 1;
        }
        cout << '\n';
    }

    return 0;
}
