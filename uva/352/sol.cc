#include <bits/stdc++.h>
using namespace std;

#ifdef DEBUG
	#define debug(args...)            { dbg,args; cerr << endl; }
#else
    #define debug(args...)              // Just strip off all debug tokens
#endif

struct debugger
{
    template<typename T> debugger& operator , (const T& v)
    {    
        cerr << v << ' ';
        return *this;
    }
} dbg;

vector<int> dx = {-1, 0, 1, -1, 1, -1, 0, 1};
vector<int> dy = {-1, -1, -1, 0, 0, 1, 1, 1};

void bfs(vector<vector<int>> &board, int r, int c)
{
	queue<pair<int, int>> Q;
	Q.push({r, c});
	while (!Q.empty()) {
		r = Q.front().first;
		c = Q.front().second;
		Q.pop();
		board[r][c] = 0;
		for (int i = 0; i < 8; ++i) {
			int x = r+dx[i], y = c+dy[i];
			if (0 <= x && x < board.size() &&
				0 <= y && y < board[0].size() &&
				board[x][y] == 1)
				Q.push({x, y});
		}
	}
}

int main() 
{
	int n, r = 0;
	string row;
	while (cin >> n) {
		++r;
		int cnt = 0;
		vector<vector<int>> board(n, vector<int>(n));
		for (int r = 0; r < n; ++r) {
			cin >> row;
			for (int c = 0; c < n; ++c) {
				board[r][c] = row[c]-'0';
			}
		}
		for (int r = 0; r < n; ++r) {
			for (int c = 0; c < n; ++c) {
				if (board[r][c] == 1) {
					++cnt;
					bfs(board, r, c);
				}
			}
		}
		printf("Image number %d contains %d war eagles.\n", r, cnt);
	}
}
