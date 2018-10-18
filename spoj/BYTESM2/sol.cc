#include <bits/stdc++.h>
using namespace std;

#ifdef DEBUG
    #define dbg(...) fprintf(stderr, __VA_ARGS__)
#else
    #define dbg(...)
#endif

const int N_MAX = 105;
int board[N_MAX][N_MAX];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int T, R, C;
    cin >> T;
    while (T--) {
        cin >> R >> C;
        for (int r = 1; r <= R; ++r) {
            memset(board[r], 0, sizeof(board[r]));
            for (int c = 1; c <= C; ++c) {
                cin >> board[r][c];
            }
        }
        for (int r = 2; r <= R; ++r) {
            for (int c = 1; c <= C; ++c) {
                board[r][c] += max(board[r-1][c-1], max(board[r-1][c], board[r-1][c+1]));
            }
        }
        int ans = 0;
        for (int c = 1; c <= C; ++c) {
            if (board[R][c] > ans)
                ans = board[R][c];
        }
        cout << ans << '\n';
    }

    return 0;
}
