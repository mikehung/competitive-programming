#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <vector>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <queue>
#include <ctime>
#include <cassert>
#include <complex>
#include <string>
#include <cstring>
using namespace std;

vector<int> dir = {0, 1, 0, -1, 0};

int main()
{
	string door = "BYRG", key = "byrg";
    const int NMAX = 101;
	int R, C, r, c, x, y;
    int board[NMAX][NMAX][16];
	while (cin >> R >> C) {
		if (R == 0 && C == 0) return 0;
		queue<pair<int, int>> Q;
		vector<string> board(R);
        map<int, int> steps;
		map<int, set<char> stats;
		set<char> keys;
		for (r = 0; r < R; ++r) {
			cin >> board[r];
			for (c = 0; c < C; ++c) {
				if (board[r][c] == '*') {
					Q.push(make_tuple(r, c));
                    steps[r*C+c] = 0;
					stats[r*C+c] = keys;
					board[r][c] = '.';
				}
			}
		}
		int step = -1;
		while (!Q.empty() && step == -1) {
			tie(r, c) = Q.front();
			Q.pop();
			for (int i = 0; i < 4; ++i) {
				x = r + dir[i], y = c + dir[i+1];
				bool is_key = false;
				if (0 <= x && x < R && 0 <= y && y < C) {
					if (board[x][y] == '#') {
						continue;
					} else if (door.find(board[x][y]) != string::npos) {
						if (!stats[r*C+c].count(tolower(board[x][y])))
							continue;
					} else if (key.find(board[x][y]) != string::npos) {
						is_key = true;
					} else if (board[x][y] == 'X') {
						step = steps[r*C+c]+1;
						break;
                    }
					if (steps[x*C+y] != -1 && !is_key && stats[r*C+c] == stats[x*C+y] && steps[x*C+y] < steps[r*C+c]+1)
						continue;
					Q.push(make_tuple(x, y));
					steps[x*C+y] = steps[r*C+c]+1;
					stats[x*C+y] = stats[r*C+c];
					if (is_key) {
						stats[x*C+y].insert(board[x][y]);
						board[x][y] = '.';
					}
				}
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
