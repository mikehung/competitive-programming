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

int n, m;
long long k, ans = 0;
vector<vector<long long>> board;
vector<unordered_map<long long, long long>> mid_cnt(400);

void dfs(long long val, int step, int r, int c)
{
	if (r >= n || c >= m)
		return;
	val ^= board[r][c];
	if (step == 0) {
		++mid_cnt[r*m+c][val];
		return;
	}
	dfs(val, step-1, r+1, c);
	dfs(val, step-1, r, c+1);
}

void dfs2(long long val, int step, int r, int c)
{
	if (r < 0 || c < 0)
		return;
	if (step == 0) {
		ans += mid_cnt[r*m+c][val];
		return;
	}
	val ^= board[r][c];
	dfs2(val, step-1, r-1, c);
	dfs2(val, step-1, r, c-1);
}

int main()
{
	cin >> n >> m >> k;
	board.resize(n);
	for (int r = 0; r < n; ++r) {
		board[r].resize(m);
		for (int c = 0; c < m; ++c) {
			cin >> board[r][c];
		}
	}
	int mid_step = (n+m-2)/2;
	dfs(k, mid_step, 0, 0);
	dfs2(0, n+m-2-mid_step, n-1, m-1);
	cout << ans << '\n';
}
