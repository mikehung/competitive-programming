#include <bits/stdc++.h>
using namespace std;

#ifdef DEBUG
	#define debug(args...)	{ dbg,args; cerr << endl; }
#else
	#define debug(args...)	// do nothing
#endif

struct debugger
{
    template<typename T> debugger& operator , (const T& v)
    {    
        cerr << v << ' ';
        return *this;
    }
} dbg;

int v(char c)
{
	return c == '#' ? -1 : 1;
}

int main() 
{
	vector<string> board(4);
	for (int i = 0; i < 4; ++i) {
		cin >> board[i];
	}
	int val;
	for (int r = 0; r < 3; ++r) {
		for (int c = 0; c < 3; ++c) {
			val = v(board[r][c]) + v(board[r+1][c]) + v(board[r][c+1]) + v(board[r+1][c+1]);
			if (val != 0) {
				cout << "YES\n";
				return 0;
			}
		}
	}
	cout << "NO\n";
}
