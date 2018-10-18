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

vector<int> Parent, Rank;

int find(int u)
{
	if (Parent[u] != u)
		Parent[u] = find(Parent[u]);
	return Parent[u];
}

int merge(int u, int v)
{
	u = find(u);
	v = find(v);
	if (u != v) {
		if (Rank[u] < Rank[v])
			swap(u, v);
		Parent[v] = u;
		if (Rank[u] == Rank[v])
			++Rank[u];
		return 1;
	}
	return 0;
}

int main()
{
	int n, m, q, u, v, groups;
	cin >> n >> m >> q;
	groups = n+m;
	Parent.resize(n+m);
	Rank.resize(n+m);
	for (int i = 0; i < Parent.size(); ++i)
		Parent[i] = i;
	for (int i = 0; i < q; ++i) {
		cin >> u >> v;
		--u;
		v += n-1;
		groups -= merge(u, v);
	}
	cout << groups-1 << '\n';
}
