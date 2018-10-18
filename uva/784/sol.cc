#include <stdio.h>
#include <queue>
using namespace std;

typedef pair<int, int> pii;

const int R = 33, C = 88;
char maze[R][C];

void dfs(int r, int c)
{
	maze[r][c] = '#';
	if (r+1 < R && maze[r+1][c] == ' ')
		dfs(r+1, c);
	if (r > 0 && maze[r-1][c] == ' ')
		dfs(r-1, c);
	if (c+1 < C && maze[r][c+1] == ' ')
		dfs(r, c+1);
	if (c > 0 && maze[r][c-1] == ' ')
		dfs(r, c-1);
}

void solve()
{
	for (int r = 0; r < R; ++r) {
		for (int c = 0; c < C; ++c) {
			if (maze[r][c] == '*')
				dfs(r, c);
		}
	}
}

int main()
{
	int t, n, r;
	scanf("%d ", &t);
	while (t--) {
		n = 0;
		while (gets(maze[n])) {
			if (maze[n][0] == '_') {
				break;
			}
			++n;
		}
		solve();
		for (r = 0; r <= n; ++r)
			puts(maze[r]);
	}

	return 0;
}
// Time: O(mn), Space: O(mn), mn = maze size
