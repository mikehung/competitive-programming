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
    #define dbg(...) fprintf(stderr, __VA_ARGS__)
#else
    #define dbg(...)
#endif

typedef long long ll;
typedef pair<int, int> pii;

const int N_MAX = 200000 + 5;
int n, m, k, degree[N_MAX], ans[N_MAX];
pii edges[N_MAX];
set<int> G[N_MAX];
set<pii> S;


void remove_edge(int u, int v)
{
	if (!G[u].count(v)) return;
    S.erase(make_pair(G[u].size(), u));
    G[u].erase(v);
    if (!G[u].empty())
        S.insert(make_pair(G[u].size(), u));

    S.erase(make_pair(G[v].size(), v));
    G[v].erase(u);
    if (!G[v].empty())
        S.insert(make_pair(G[v].size(), v));
}

int main()
{
    int u, v;
    scanf("%d %d %d", &n, &m, &k);
    for (int i = 0; i < m; ++i) {
        scanf("%d %d", &u, &v);
        G[u].insert(v);
        G[v].insert(u);
        edges[i] = make_pair(u, v);
    }
    for (int i = 1; i <= n; ++i) {
		degree[i] = G[i].size();
        S.insert(make_pair(degree[i], i));
    }
    for (int i = m-1; i >= 0; --i) {
		while (!S.empty() && S.begin()->first < k) {
			u = S.begin()->second;
			for (auto v : G[u]) {
				S.erase(make_pair(degree[v], v));
				--degree[v];
				if (degree[v])
					S.insert(make_pair(degree[v], v));
			}
			S.erase(make_pair(degree[u], u));
			degree[u] = 0;
		}
        ans[i] = S.size();
		u = edges[i].first, v = edges[i].second;
		if (degree[u] && degree[v]) {
			S.erase(make_pair(degree[u], u));
			--degree[u];
			if (degree[u])
				S.insert(make_pair(degree[u], u));

			S.erase(make_pair(degree[v], v));
			--degree[v];
			if (degree[v])
				S.insert(make_pair(degree[v], v));
		}
    }
    for (int i = 0; i < m; ++i)
        printf("%d\n", ans[i]);

    return 0;
}
// Time: O(), Space: O()
