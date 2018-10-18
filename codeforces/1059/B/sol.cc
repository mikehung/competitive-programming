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
int dr[8] = {-1, 0, 1, -1, 1, -1, 0, 1};
int dc[8] = {-1, -1, -1, 0, 0, 1, 1, 1};

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> m;
    for (int r = 0; r < n; ++r) {
        cin >> board[r];
    }
    for (int r = 1; r < n-1; ++r) {
        for (int c = 1; c < m-1; ++c) {
            bool flag = true;
            for (int i = 0; i < 8; ++i) {
                if (board[r+dr[i]][c+dc[i]] != '#') {
                    flag = false;
                    break;
                }
            }
            draw[r][c] = flag;
        }
    }
    for (int r = 0; r < n; ++r) {
        for (int c = 0; c < m; ++c) {
            if (board[r][c] == '.') continue;
            bool flag = false;
            for (int i = 0; i < 8; ++i) {
                int x = r+dr[i], y = c+dc[i];
                if (x < 0 || x >= n || y < 0 || y >= m) continue;
                if (draw[x][y]) {
                    flag = true;
                    break;
                }
            }
            if (!flag) {
                cout << "NO\n";
                return 0;
            }
        }
    }
    cout << "YES\n";

    return 0;
}
