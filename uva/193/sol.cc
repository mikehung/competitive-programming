#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <vector>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <queue>
#include <ctime>
#include <cassert>
#include <complex>
#include <string>
#include <cstring>
using namespace std;

#ifdef DEBUG
	#define eprintf(...) fprintf(stderr, __VA_ARGS__)
#else
	#define eprintf(...)
#endif

typedef long long ll;
typedef pair<int, int> pii;

const int NMAX = 105;
int T, N, M;
int Color[NMAX];
set<int> Graph[NMAX];
vector<int> ans;

void dfs(int u, vector<int> &cur)
{
	if (u == N + 1) {
		for (auto x : cur)
			cerr << x << ' ';
		cerr << '\n';
		if (cur.size() > ans.size())
			ans = cur;
		return;
	}
	if (Color[u] != 0) {
		dfs(u+1, cur);
		return;
	}

	Color[u] = 1;  // white
	dfs(u+1, cur);

	Color[u] = 2;  // black
	for (auto v : Graph[u]) {
		if (v < u) continue;
		Color[v] = 1;
	}
	cur.push_back(u);
	dfs(u+1, cur);
	cur.pop_back();
	for (auto v : Graph[u]) {
		if (v < u) continue;
		Color[v] = 0;
	}
	Color[u] = 0;
}

int main()
{
	int u, v;
	cin >> T;
	while (T--) {
		memset(Color, 0, sizeof(Color));
		for (int i = 0; i < NMAX; ++i)
			Graph[i].clear();
		ans.clear();
		cin >> N >> M;
		for (int i = 0; i < M; ++i) {
			cin >> u >> v;
			Graph[u].insert(v);
			Graph[v].insert(u);
		}
		vector<int> cur;
		dfs(1, cur);
		cout << ans.size() << '\n';
		bool first = true;
		for (auto x : ans) {
			if (!first)
				cout << ' ';
			first = false;
			cout << x;
		}
		cout << '\n';
	}
	return 0;
}
// Time: O(), Space: O()
