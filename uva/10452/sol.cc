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

string path = "@IEHOVA#";

bool dfs(vector<vector<char>> &board, int r, int c, int i, vector<string> &steps)
{
	if (r < 0 || r >= board.size())
		return false;
	if (c < 0 || c >= board[0].size())
		return false;
	if (board[r][c] != path[i])
		return false;
	if (path[i] == '#')
		return true;

	steps.push_back("forth");
	if (dfs(board, r-1, c, i+1, steps)) return true;
	steps.pop_back();

	steps.push_back("left");
	if (dfs(board, r, c-1, i+1, steps)) return true;
	steps.pop_back();

	steps.push_back("right");
	if (dfs(board, r, c+1, i+1, steps)) return true;
	steps.pop_back();
}

int main() 
{
	int t, m, n;
	cin >> t;
	while (t--) {
		cin >> m >> n;
		vector<vector<char>> board(m, vector<char>(n));
		vector<string> steps;
		for (int r = 0; r < m; ++r) {
			for (int c = 0; c < n; ++c) {
				cin >> board[r][c];
			}
		}
		int r = m-1, c = 0;
		while (board[r][c] != '@') ++c;
		dfs(board, r, c, 0, steps);
		cout << steps[0];
		for (int i = 1; i < steps.size(); ++i)
			cout << ' ' << steps[i];
		cout << '\n';
	}
}
