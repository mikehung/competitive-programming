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

const int N = 2123;
int Parent[N], Rank[N];

struct Edge {
	int c, u, v;
};

bool byCost(const Edge &e1, const Edge &e2)
{
	return e1.c < e2.c;
}

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
	int t, n, e, c;
	string a, b;
	cin >> t;
	while (t--) {
		cin >> n >> e;
		for (int i = 0; i < n; ++i) {
			Parent[i] = i;
			Rank[i] = 0;
		}
		int id = 0;
		Edge edge;
		vector<Edge> edges;
		map<string, int> ids;
		for (int i = 0; i < e; ++i) {
			cin >> a >> b >> c;
			if (!ids.count(a))
				ids[a] = id++;
			if (!ids.count(b))
				ids[b] = id++;
			edge.u = ids[a];
			edge.v = ids[b];
			edge.c = c;
			edges.push_back(edge);
		}
		sort(edges.begin(), edges.end(), byCost);
		int cnt = n, i = 0, ans = 0;
		while (cnt != 1) {
			edge = edges[i++];
			if (merge(edge.u, edge.v)) {
				--cnt;
				ans += edge.c;
			}
		}
		cout << ans << '\n';
		if (t)
			cout << '\n';
	}

	return 0;
}
// Time: O(), Space: O()
