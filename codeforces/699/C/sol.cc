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

vector<vector<int>> dp;

int solve(int i, int last, int cnt, const vector<int> &a)
{
	++i;
	if (dp[i][last] != -1)
		return dp[i][last];
	int ans;
	if (i == a.size())
		ans = cnt;
	else if (a[i] == 0)
		ans = solve(i, 0, cnt, a);
	else if (a[i] == 1) {
		if (last == 1)
			ans = solve(i, 0, cnt, a);
		else
			ans = max(solve(i, 0, cnt, a), solve(i, 1, cnt+1, a));
	} else if (a[i] == 2) {
		if (last == 2)
			ans = solve(i, 0, cnt, a);
		else
			ans = max(solve(i, 0, cnt, a), solve(i, 2, cnt+1, a));
	} else if (a[i] == 3) {
		if (last == 0)
			ans = max(solve(i, 0, cnt, a), max(solve(i, 1, cnt+1, a), solve(i, 2, cnt+1, a)));
		else if (last == 1)
			ans = max(solve(i, 0, cnt, a), solve(i, 2, cnt+1, a));
		else if (last == 2)
			ans = max(solve(i, 0, cnt, a), solve(i, 1, cnt+1, a));
	}
	dp[i][last] = ans;
	return dp[i][last];
}

int main()
{
	int n;
	cin >> n;
	vector<int> a(n);
	dp = vector<vector<int>> (101, vector<int>(3, -1));
	for (int i = 0; i < n; ++i)
		cin >> a[i];
	int cnt = 0;  // 0: rest, 1: contest, 2: gym
	int work = solve(-1, 0, cnt, a);
	cout << n-work << '\n';
}
