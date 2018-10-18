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

void dfs(vector<vector<char>> &board, int r, int c, bool &ship)
{
	if (r < 0 || r >= board.size() || c < 0 || c >= board[0].size() || board[r][c] == '.')
		return;
	if (board[r][c] == 'x')
		ship = true;
	board[r][c] = '.';
	dfs(board, r-1, c, ship);
	dfs(board, r+1, c, ship);
	dfs(board, r, c-1, ship);
	dfs(board, r, c+1, ship);
}

int main() 
{
	int round;
	cin >> round;
	for (int i = 1; i <= round; ++i) {
		int n, cnt = 0;
		cin >> n;
		vector<vector<char>> board(n, vector<char>(n));
		for (int r = 0; r < n; ++r)
			for (int c = 0; c < n; ++c)
				cin >> board[r][c];
		for (int r = 0; r < n; ++r) {
			for (int c = 0; c < n; ++c) {
				if (board[r][c] != '.') {
					bool ship = false;
					dfs(board, r, c, ship);
					if (ship) ++cnt;
				}
			}
		}
		printf("Case %d: %d\n", i, cnt);
	}
}
