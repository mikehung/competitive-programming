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

vector<int> a(15);
int n, l, r, x;
long long res;

void dfs(int id, int amin, int amax, long long total, int cnt)
{
	if (id == n) {
		if (cnt >= 2 && l <= total && total <= r && amax-amin >= x)
			++res;
		return;
	}
	dfs(id+1, amin, amax, total, cnt);
	dfs(id+1, min(amin, a[id]), max(amax, a[id]), total+a[id], cnt+1);
}

int main()
{
	cin >> n >> l >> r >> x;
	for (int i = 0; i < n; ++i)
		cin >> a[i];
	dfs(0, INT_MAX, INT_MIN, 0, 0);
	cout << res << '\n';
}
