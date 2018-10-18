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

static const int X = 555;
int T, N, M;
vector<set<int>> G(X);
vector<int> degree(X);

int main() 
{
	int u, v;
	cin >> T;
	while (T--) {
		cin >> N;
		set<int> all_nodes;
		for (int i = 1; i <= N; ++i)
			all_nodes.insert(i);
		for (int i = 1; i <= N; ++i) {
			cin >> u;
			all_nodes.erase(u);
			G[u] = all_nodes;
			degree[u] = i-1;
		}
		cin >> M;
		for (int i = 1; i <= M; ++i) {
			cin >> u >> v;
			if (G[u].count(v)) {
				swap(u, v);
			}
			G[v].erase(u);
			G[u].insert(v);
			++degree[v];
			--degree[u];
		}
		queue<int> Q;
		vector<int> ans;
		for (int i = 1; i <= N; ++i)
			if (degree[i] == 0)
				Q.push(i);

		while (!Q.empty()) {
			u = Q.front();
			Q.pop();
			ans.push_back(u);
			for (int w : G[u]) {
				if (--degree[w] == 0)
					Q.push(w);
			}
		}
		if (ans.size() != N) {
			cout << "IMPOSSIBLE\n";
		} else {
			for (int i = 0; i < ans.size(); ++i) {
				if (i != ans.size()-1)
					cout << ans[i] << ' ';
				else
					cout << ans[i] << '\n';
			}
		}
	}
}
