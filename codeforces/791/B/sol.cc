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

void dfs(vector<unordered_set<int>> &G, vector<bool> &visit, int u, long long &V, long long &E)
{
	visit[u] = true;
	++V;
	for (int v : G[u]) {
		++E;
		if (!visit[v]) {
			dfs(G, visit, v, V, E);
		}
	}
}

int main()
{
	int n, m, u, v;
	cin >> n >> m;
	vector<bool> visit(n+1);
	vector<unordered_set<int>> G(n+1);
	for (int i = 0; i < m; ++i) {
		cin >> u >> v;
		G[u].insert(v);
		G[v].insert(u);
	}
	for (int i = 1; i < n+1; ++i) {
		if (visit[i]) continue;
		long long V = 0, E = 0;
		dfs(G, visit, i, V, E);
		if (V*(V-1) != E) {
			puts("NO");
			return 0;
		}
	}
	puts("YES");
}
