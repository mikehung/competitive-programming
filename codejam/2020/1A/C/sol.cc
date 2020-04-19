#include <bits/stdc++.h>

using namespace std;

vector<vector<pair<int, int>>> Up, Down, Left, Right;

pair<int, int> neighbor(const pair<int, int> &par, int dir)
{
    if (dir == 0) return Up[par.first][par.second];
    if (dir == 1) return Down[par.first][par.second];
    if (dir == 2) return Left[par.first][par.second];
    return Right[par.first][par.second];
}

void solve()
{
    int R, C;
    long long total = 0, an = 0;
    cin >> R >> C;

    vector<vector<int>> ma(R, vector<int>(C)), when(R, vector<int>(C));
    vector<pair<int, int>> check;

    Up = vector<vector<pair<int, int>>>(R, vector<pair<int, int>>(C));
    Down = vector<vector<pair<int, int>>>(R, vector<pair<int, int>>(C));
    Left = vector<vector<pair<int, int>>>(R, vector<pair<int, int>>(C));
    Right = vector<vector<pair<int, int>>>(R, vector<pair<int, int>>(C));

    for (int r = 0; r < R; ++r) {
        for (int c = 0; c < C; ++c) {
            cin >> ma[r][c];
            total += ma[r][c];

            Up[r][c] = {r-1, c};
            Down[r][c] = {r+1, c};
            Left[r][c] = {r, c-1};
            Right[r][c] = {r, c+1};
            check.push_back({r, c});
        }
    }

    int round = 0;
    while (check.size()) {
        vector<pair<int, int>> rm;
        an += total;
        ++round;

        for (auto &par: check) {
            int r = par.first, c = par.second;
            int sum = 0, cnt = 0;
            for (int dir = 0; dir < 4; ++dir) {
                auto npar = neighbor(par, dir);
                int x = npar.first, y = npar.second;
                if (x >= 0 && x < R && y >= 0 && y < C) {
                    sum += ma[x][y];
                    cnt++;
                }
            }
            if (cnt*ma[r][c] < sum) {
                rm.push_back({r, c});
                total -= ma[r][c];
                when[r][c] = round;
            }
        }

        if (rm.empty()) break;
        check.clear();
        for (auto &par: rm) {
            for (int dir = 0; dir < 4; ++dir) {
                auto npar = neighbor(par, dir);
                int x = npar.first, y = npar.second;
                if (x >= 0 && x < R && y >= 0 && y < C && when[x][y] != round) {
                    check.push_back({x, y});
                    when[x][y] = round;
                }
            }
        }

        for (auto &par: rm) {
            int r = par.first, c = par.second;
            pair<int, int> npar;
            npar = Up[r][c];
            if (npar.first >= 0) {
                Down[npar.first][npar.second] = Down[r][c];
            }
            npar = Down[r][c];
            if (npar.first < R) {
                Up[npar.first][npar.second] = Up[r][c];
            }
            npar = Left[r][c];
            if (npar.second >= 0) {
                Right[npar.first][npar.second] = Right[r][c];
            }
            npar = Right[r][c];
            if (npar.second < C) {
                Left[npar.first][npar.second] = Left[r][c];
            }
        }
    }

    cout << an << '\n';
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout << fixed << setprecision(6);
    int T;
    cin >> T;
    for (int t = 1; t <= T; ++t) {
        cout << "Case #" << t << ": ";
        solve();
    }
    return 0;
}
