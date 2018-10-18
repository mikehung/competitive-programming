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
#include <climits>
using namespace std;

#ifdef DEBUG
	#define eprintf(...) fprintf(stderr, __VA_ARGS__)
#else
	#define eprintf(...)
#endif

typedef long long ll;
typedef pair<int, int> pii;
int d[5] = {0, 1, 0, -1, 0};
int n, m;

void bfs(vector<vector<int>> &board, int r, int c)
{
	int x, y;
	queue<pii> Q;
	Q.push(make_pair(r, c));
	board[r][c] = 0;
	while (!Q.empty()) {
		r = Q.front().first;
		c = Q.front().second;
		Q.pop();
		for (int i = 0; i < 4; ++i) {
			x = r + d[i], y = c + d[i+1];
			if (0 <= x && x < n && 0 <= y && y < m && board[x][y] > board[r][c] + 1) {
				board[x][y] = board[r][c] + 1;
				Q.push(make_pair(x, y));
			}
		}
	}
}

int main()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	int k, x, y;
	cin >> n >> m >> k;
	vector<vector<int>> board(n, vector<int>(m, INT_MAX));
	for (int i = 0; i < k; ++i) {
		cin >> x >> y;
		bfs(board, x-1, y-1);
	}
	int maxr = 0, maxc = 0;
	for (int r = 0; r < n; ++r) {
		for (int c = 0; c < m; ++c) {
			if (board[r][c] > board[maxr][maxc]) {
				maxr = r, maxc = c;
			}
		}
	}
	cout << maxr + 1 << ' ' << maxc + 1 << '\n';

	return 0;
}
// Time: O(nm), Space: O(nm)
