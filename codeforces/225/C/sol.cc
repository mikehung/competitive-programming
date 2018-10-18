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

int get_x_cnt_by_col(int c, vector<string> &board)
{
	int cnt = 0;
	for (int r = 0; r < board.size(); ++r)
		if (board[r][c] == '#')
			++cnt;
	return cnt;
}

int main()
{
	int n, m, x, y;
	cin >> n >> m >> x >> y;
	vector<string> board(n);
	for (int r = 0; r < n; ++r)
		cin >> board[r];
	vector<long long> x_dp(y+1, INT_MAX), o_dp(y+1, INT_MAX);
	long long x_cnt, o_cnt, x_min, o_min;
	x_dp[1] = o_dp[1] = 0;
	debug("xxx", x);
	debug("wow", x_dp[1], o_dp[1]);
	for (int c = 0; c < x; ++c) {
		x_cnt = get_x_cnt_by_col(c, board);
		o_cnt = n-x_cnt;
		x_dp[1] += n-x_cnt;
		o_dp[1] += x_cnt;
		debug("wow", x_dp[1], o_dp[1]);
	}
	for (int c = x; c < m; ++c) {
		x_cnt = get_x_cnt_by_col(c, board);
		o_cnt = n-x_cnt;
		x_min = INT_MAX;
		o_min = INT_MAX;
		for (int i = x; i < y+1; ++i) {
			x_min = min(x_min, x_dp[i]);
			o_min = min(o_min, o_dp[i]);
		}
		for (int i = y; i >= 2; --i) {
			if (x_dp[i-1] != INT_MAX)
				x_dp[i] = x_dp[i-1] + o_cnt;
			if (o_dp[i-1] != INT_MAX)
				o_dp[i] = o_dp[i-1] + x_cnt;
		}
		if (o_min != INT_MAX)
			x_dp[1] = o_min + o_cnt;
		if (x_min != INT_MAX)
			o_dp[1] = x_min + x_cnt;
		cerr << "x_dp:\n";
		for (int i = 0; i < x_dp.size(); ++i)
			cerr << x_dp[i] << ' ';
		cerr << "\no_dp:\n";
		for (int i = 0; i < x_dp.size(); ++i)
			cerr << o_dp[i] << ' ';
		cerr << "\n";
	}
	long long res = INT_MAX;
	for (int i = x; i < y+1; ++i) {
		if (m-i != 0 && m-i < x) continue;
		res = min(res, min(x_dp[i], o_dp[i]));
	}
	cout << res << '\n';
}
