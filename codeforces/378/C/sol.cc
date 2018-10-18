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

#ifdef DEBUG
	#define dbg(...) fprintf(stderr, __VA_ARGS__)
#else
	#define dbg(...)
#endif

const int NMAX = 503;
int n, m, k, s = 0;
string maze[NMAX];
int dir[5] = {0, 1, 0, -1, 0};

int main()
{
	int sr, sc, x, y, r, c;
	cin >> n >> m >> k;
	for (r = 0; r < n; ++r) {
		cin >> maze[r];
		for (c = 0; c < m; ++c) {
			if (maze[r][c] == '.') {
				++s;
				sr = r;
				sc = c;
			}
		}
	}
	int cnt= s - k;
	if (cnt) {
		queue<pair<int, int>> Q;

		Q.push(make_pair(sr, sc));
		maze[sr][sc] = 'E';
		--cnt;
		while (cnt) {
			r = Q.front().first;
			c = Q.front().second;
			Q.pop();
			for (int d = 0; d < 4 && cnt; ++d) {
				x = r + dir[d], y = c + dir[d+1];
				if (x >= 0 && x < n && y >= 0 && y < m && maze[x][y] == '.') {
					Q.push(make_pair(x, y));
					maze[x][y] = 'E';
					--cnt;
				}
			}
		}
	}

	for (r = 0; r < n; ++r) {
		for (c = 0; c < m; ++c) {
			if (maze[r][c] == '.')
				maze[r][c] = 'X';
			else if (maze[r][c] == 'E')
				maze[r][c] = '.';
		}
		cout << maze[r] << '\n';
	}

	return 0;
}
// Time: O(), Space: O()
