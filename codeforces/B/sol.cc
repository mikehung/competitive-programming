#include <bits/stdc++.h>
using namespace std;

#ifdef DEBUG
    #define dbg(...) fprintf(stderr, __VA_ARGS__)
#else
    #define dbg(...)
#endif

const int MAX = 1005;
int n, m, draw[MAX][MAX];
char board[MAX][MAX];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> m;
    for (int r = 1; r <= n; ++r) {
        for (int c = 1; c <= m; ++c) {
            cin >> board[r][c];
        }
    }
    for (int r = 1; r <= n; ++r) {
        for (int c = 1; c <= m; ++c) {
            cout << board[r][c] << ' ';
        }
        cout << '\n';
    }


    return 0;
}
