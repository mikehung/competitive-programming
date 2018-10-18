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

int max_cnt(vector<vector<pair<long long, int>>> &DP, int i, int pos)
{
	int cnt = 0;
	for (int j = 0; j < 3; ++j) {
		if (DP[i-1][j].first < pos)
			cnt = max(cnt, DP[i-1][j].second);
	}
	return cnt;
}

int main()
{
	int n, cnt;
	cin >> n;
	vector<long long> X(n), H(n);
	vector<vector<pair<long long, int>>> DP(n, vector<pair<long long, int>>(3));
	for (int i = 0; i < n; ++i) {
		cin >> X[i] >> H[i];
	}
	DP[0][0] = {X[0], 0};  // not cut
	DP[0][1] = {X[0], 1};  // fell to left
	DP[0][2] = {X[0]+H[0], 1};  // fell to right
	for (int i = 1; i < n; ++i) {
		cnt = max_cnt(DP, i, X[i]-H[i]);
		DP[i][1] = {X[i], cnt+1};

		cnt = max_cnt(DP, i, X[i]);
		DP[i][0] = {X[i], cnt};
		DP[i][2] = {X[i]+H[i], cnt+1};
	}
	cout << max(DP[n-1][0].second, max(DP[n-1][1].second, DP[n-1][2].second)) << '\n';
}
