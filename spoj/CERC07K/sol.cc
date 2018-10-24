#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <queue>
#include <string>
#include <cstring>
#include <algorithm>
#include <tuple>

using namespace std;

int dir[5] = {0, 1, 0, -1, 0};

int main()
{
	string door = "BYRG", key = "byrg";
    const int NMAX = 101;
	int R, C, r, c, x, y, mask, new_mask, pos, step;
    char board[NMAX][NMAX];
    int visit[NMAX][NMAX][16];
    while (cin >> R >> C) {
		if (R == 0 && C == 0) return 0;
        queue<tuple<int, int, int>> Q;
        memset(visit, -1, sizeof(visit));
        for (r = 0; r < R; ++r) {
            scanf("%s", &board[r][0]);
            for (c = 0; c < C; ++c) {
                if (board[r][c] == '*') {
                    visit[r][c][0] = 0;
                    Q.push(make_tuple(r, c, 0));
                }
            }
        }
        step = -1;
        while (!Q.empty() && step == -1) {
            tie(r, c, mask) = Q.front();
            Q.pop();
            for (int i = 0; i < 4; ++i) {
                x = r + dir[i], y = c + dir[i+1];
                if (x < 0 || x >= R || y < 0 || y >= C || board[x][y] == '#')
                    continue;
                new_mask = mask;
                if ((pos = door.find(board[x][y])) != string::npos) {
                    if (((mask >> pos) & 1) == 0)
                        continue;
                } else if ((pos = key.find(board[x][y])) != string::npos) {
                    new_mask |= (1 << pos);
                } else if (board[x][y] == 'X') {
                    step = visit[r][c][mask] + 1;
                    break;
                }
                if (visit[x][y][new_mask] != -1)
                    continue;
                visit[x][y][new_mask] = visit[r][c][mask] + 1;
                Q.push(make_tuple(x, y, new_mask));
            }
        }
		if (step == -1) {
			printf("The poor student is trapped!\n");
		} else {
			printf("Escape possible in %d steps.\n", step);
		}
	}

	return 0;
}
// Time: O(), Space: O()
