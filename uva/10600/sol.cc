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
int T, N, M, C;

vector<pair<int, int>> MST[NMAX];
vector<tuple<int, int, int>> Edges;
vector<bool> Used;
int Parent[NMAX];
int Rank[NMAX];

void init()
{
	C = 0;
	Edges.clear();
	Used.clear();
	Edges.resize(M);
	Used.resize(M);
	for (int i = 1; i <= N; ++i) {
		MST[i].clear();
		Parent[i] = i;
		Rank[i] = 0;
	}
}

int find(int x)
{
	if (Parent[x] != x) {
		Parent[x] = find(Parent[x]);
	}
	return Parent[x];
}

int merge(int x, int y)
{
	x = find(x), y = find(y);
	if (x != y) {
		if (Rank[x] < Rank[y])
			swap(x, y);
		Parent[y] = x;
		if (Rank[x] == Rank[y])
			++Rank[x];
		return 1;
	}
	return 0;
}

bool dfs(int u, int p, int e, vector<int> &cycle)
{
	if (u == e)
		return true;
	int c, v;
	for (auto &edge : MST[u]) {
		c = edge.first;
		v = edge.second;
		if (v == p) continue;
		cycle.push_back(c);
		if (dfs(v, u, e, cycle))
			return true;
		cycle.pop_back();
	}
	return false;
}

int main()
{
	int u, v, c;
	cin >> T;
	while (T--) {
		cin >> N >> M;
		init();
		for (int i = 0; i < M; ++i) {
			cin >> u >> v >> c;
			Edges[i] = make_tuple(c, u, v);
		}
		sort(Edges.begin(), Edges.end());
		for (int i = 0; i < Edges.size(); ++i) {
			tie(c, u, v) = Edges[i];
			if (merge(u, v)) {
				MST[u].push_back(make_pair(c, v));
				MST[v].push_back(make_pair(c, u));
				C += c;
				Used[i] = true;
			}
		}

		int min_diff = -1, max_edge;
		for (int i = 0; i < Edges.size(); ++i) {
			if (Used[i]) continue;
			tie(c, u, v) = Edges[i];
			vector<int> cycle;
			dfs(u, 0, v, cycle);
			if (cycle.empty()) continue;
			max_edge = *max_element(cycle.begin(), cycle.end());
			if (min_diff == -1 || min_diff > c-max_edge)
				min_diff = c-max_edge;
		}

		cout << C << ' ' << C+min_diff << '\n';
	}
	return 0;
}
// Time: O(), Space: O()
