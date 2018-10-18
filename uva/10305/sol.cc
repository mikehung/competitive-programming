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

int main() 
{
	int n, m, u, v;
	while (true) {
		cin >> n >> m;
		if (n == 0 && m == 0)
			break;
		vector<vector<int>> graph(n+1);
		vector<int> degree(n+1);
		for (int i = 0; i < m; ++i) {
			cin >> u >> v;
			graph[u].push_back(v);
			++degree[v];
		}
		queue<int> Q;
		for (int i = 1; i <= n; ++i) {
			if (degree[i] == 0) {
				Q.push(i);
			}
		}
		while (!Q.empty()) {
			u = Q.front();
			Q.pop();
			cout << u << ' ';
			for (auto uu : graph[u]) {
				if (--degree[uu] == 0)
					Q.push(uu);
			}
		}
		cout << '\n';
	}
}
