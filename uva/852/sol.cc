#include <bits/stdc++.h>
using namespace std;

#ifdef DEBUG
    #define dbg(...) fprintf(stderr, __VA_ARGS__)
#else
    #define dbg(...)
#endif

const int N = 9;
vector<string> board(N), black(N), white(N);
int T, b, w;
vector<int> dr = {1, -1, 0, 0};
vector<int> dc = {0, 0, 1, -1};

void bfs(vector<string> &board, vector<vector<bool>> &visit, int r, int c, char stone)
{
    if (visit[r][c]) return;
    int x, y;
    queue<pair<int, int>> Q;
    board[r][c] = stone;
    Q.push({r, c});
    visit[r][c] = true;
    while (!Q.empty()) {
        r = Q.front().first;
        c = Q.front().second;
        Q.pop();
        for (int i = 0; i < 4; ++i) {
            x = r + dr[i], y = c + dc[i];
            if (x < 0 || x >= N || y < 0 || y >= N || visit[x][y] || (board[x][y] != stone && board[x][y] != '.')) continue;
            board[x][y] = stone;
            Q.push({x, y});
            visit[x][y] = true;
        }
    }
}

void go(vector<string> &board, char stone)
{
    vector<vector<bool>> visit(N, vector<bool>(N));
    for (int r = 0; r < N; ++r) {
        for (int c = 0; c < N; ++c) {
            if (board[r][c] == stone) {
                bfs(board, visit, r, c, stone);
            }
        }
    }
}

void merge()
{
    for (int r = 0; r < N; ++r) {
        for (int c = 0; c < N; ++c) {
            if (black[r][c] == 'X' && (white[r][c] == 'X' || white[r][c] == '.'))
                board[r][c] = 'X';
            else if (white[r][c] == 'O' && (black[r][c] == 'O' || black[r][c] == '.'))
                board[r][c] = 'O';
        }
    }
}

void count()
{
    b = w = 0;
    for (int r = 0; r < N; ++r) {
        for (int c = 0; c < N; ++c) {
            if (board[r][c] == 'X')
                ++b;
            else if (board[r][c] == 'O')
                ++w;
        }
    }
}

int main()
{
    cin >> T;
    for (int t = 0; t < T; ++t) {
        for (int i = 0; i < N; ++i) {
            cin >> board[i];
            black[i] = white[i] = board[i];
        }
        go(white, 'O');
        go(black, 'X');
        merge();
        count();
        printf("Black %d White %d\n", b, w);
    }
    return 0;
}
