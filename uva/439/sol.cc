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

int main() 
{
	string beg, end;
	int x0, y0, x1, y1, x, y, d, u, v;
	vector<int> dx = {-2, -2, -1, -1, 1, 1, 2, 2};
	vector<int> dy = {-1, 1, -2, 2, -2, 2, -1, 1};
	while (cin >> beg >> end) {
		vector<vector<bool>> board(8, vector<bool>(8));
		x0 = beg[0]-'a';
		y0 = beg[1]-'1';
		x1 = end[0]-'a';
		y1 = end[1]-'1';

		queue<tuple<int, int, int>> Q;
		Q.push(make_tuple(x0, y0, 0));
		board[x0][y0] = true;
		while (!Q.empty()) {
			tie(x, y, d) = Q.front();
			Q.pop();
			if (x == x1 && y == y1) {
				printf("To get from %s to %s takes %d knight moves.\n", beg.c_str(), end.c_str(), d);
				break;
			}
			for (int i = 0; i < 8; ++i) {
				u = x+dx[i], v = y+dy[i];
				if (0 <= u && u < 8 && 0 <= v && v < 8 && !board[u][v]) {
					Q.push(make_tuple(u, v, d+1));
					board[u][v] = true;
				}
			}
		}
	}
}
