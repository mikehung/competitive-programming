#include <bits/stdc++.h>
using namespace std;

#ifdef DEBUG
	#define debug(args...)            { dbg,args; cerr << endl; }
#else
    #define debug(args...)              // Just strip off all debug tokens
#endif

struct debugger
{
    template<typename T> debugger& operator , (const T& v)
    {    
        cerr << v << ' ';
        return *this;
    }
} dbg;

void dfs(unordered_map<char, vector<char>> &graph, vector<int> &visit, int depth, int p, int i, bool &cycle)
{
	visit[i] = 1;
	for (auto j : graph[i]) {
		if (j == p) continue;
		if (visit[j] == 1 && !(depth & 1)) {
			cycle = true;
		} else if (visit[j] == 0) {
			dfs(graph, visit, depth+1, i, j, cycle);
		}
	}
	visit[i] = 2;
}

int main() 
{
	int n, m, u, v, cnt = 0;
	cin >> n >> m;
	unordered_map<char, vector<char>> graph;
	for (int i = 0; i < m; ++i) {
		cin >> u >> v;
		graph[u].push_back(v);
		graph[v].push_back(u);
	}
	vector<int> visit(n+1);
	for (int i = 1; i <= n; ++i) {
		if (visit[i] == 0) {
			bool cycle = false;
			dfs(graph, visit, 0, -1, i, cycle);
			if (cycle) ++cnt;
		}
	}
	if ((n & 1) ^ (cnt & 1))
		++cnt;
	cout << cnt << '\n';
}
