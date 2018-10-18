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
	int n, m;
	cin >> n >> m;
	vector<int> a(m);
	for (int i = 0; i < m; ++i)
		cin >> a[i];

	priority_queue<int> PQ(a.begin(), a.end());
	int all = 0, cost = 0;
	for (int i = 0; i < n; ++i) {
		cost = PQ.top();
		all += cost;
		PQ.pop();
		if (cost > 1)
			PQ.push(cost-1);
	}
	cout << all << ' ';

	all = 0;
	priority_queue<int, vector<int>, greater<int>> PQ1(a.begin(), a.end());
	for (int i = 0; i < n; ++i) {
		cost = PQ1.top();
		all += cost;
		PQ1.pop();
		if (cost > 1)
			PQ1.push(cost-1);
	}
	cout << all << '\n';
}
