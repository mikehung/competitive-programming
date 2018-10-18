#include <bits/stdc++.h>
using namespace std;

#ifdef DEBUG
    #define dbg(...) fprintf(stderr, __VA_ARGS__)
#else
    #define dbg(...)
#endif

const int N_MAX = 20005, INF = 10000 * N_MAX;
int T, n, m, src, dst, u, v, w, visit[N_MAX], cost[N_MAX];
int W[N_MAX][N_MAX];
vector<int> G[N_MAX];


int main()
{
    scanf("%d", &T);
    for (int t = 1; t <= T; ++t) {
        memset(visit, 0, sizeof(visit));
        memset(cost, INF, sizeof(cost));
        for (int i = 0; i < N_MAX; ++i) {
            G[i].clear();
        }
        scanf("%d %d %d %d", &n, &m, &src, &dst);
        for (int i = 0; i < m; ++i) {
            cin >> u >> v >> w;
            G[u].push_back(v);
            G[v].push_back(u);
            W[u][v] = W[v][u] = w;
        }
        priority_queue<pair<int, int>> Q;
        Q.push({0, src});
        cost[src] = 0;
        while (!Q.empty()) {
            u = Q.top().second;
            Q.pop();
            if (visit[u]) continue;
            if (u == dst) break;
            visit[u] = 1;
            for (auto v : G[u]) {
                if (cost[v] > cost[u] + W[u][v]) {
                    cost[v] = cost[u] + W[u][v];
                    Q.push({-cost[v], v});
                }
            }
        }
        if (cost[dst] >= INF) {
            printf("Case #%d: unreachable\n", t);
        } else {
            printf("Case #%d: %d\n", t, cost[dst]);
        }
    }
    return 0;
}
