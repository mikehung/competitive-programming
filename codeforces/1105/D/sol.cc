#include <bits/stdc++.h>

using namespace std;

const int dr[4] = {1, -1, 0, 0}, dc[4] = {0, 0, 1, -1};
int n, m, p;
vector<int> ans, speed;
vector<vector<pair<int, int>>> vec;
vector<string> board;

void bfs(int pi)
{
    vector<pair<int, int>> tmpv;
    int r, c, x, y;
    for (auto &pos: vec[pi]) {
        r = pos.first, c = pos.second;
        for (int i = 0; i < 4; ++i) {
            x = r + dr[i], y = c + dc[i];
            if (0 <= x && x < n && 0 <= y && y < m && board[x][y] == '.') {
                board[x][y] = '1' + pi;
                tmpv.push_back({x, y});
            }
        }
    }
    vec[pi] = tmpv;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> m >> p;
    speed.resize(p);
    ans.resize(p);
    vec.resize(p);
    board.resize(n);

    for (auto &x: speed) {
        cin >> x;
    }

    for (auto &x: board) {
        cin >> x;
    }

    for (int r = 0; r < n; ++r) for (int c = 0; c < m; ++c) {
        if (board[r][c] != '#' && board[r][c] != '.') {
            vec[board[r][c]-'1'].push_back({r, c});
        }
    }

    bool ok = 1;
    while (ok) {
        ok = 0;
        for (int i = 0; i < p; ++i) {
            for (int j = 0; j < speed[i] && vec[i].size(); ++j) {
                ok = 1;
                bfs(i);
            }
        }
    }

    for (int r = 0; r < n; ++r) for (int c = 0; c < m; ++c) {
        if (board[r][c] != '#') {
            ans[board[r][c]-'1']++;
        }
    }
    for (auto &x: ans) {
        cout << x << ' ';
    }
    cout << '\n';

    return 0;
}
