#include <bits/stdc++.h>
using namespace std;

#ifdef DEBUG
    #define dbg(...) fprintf(stderr, __VA_ARGS__)
#else
    #define dbg(...)
#endif

const int N_MAX = 2e4 + 5, INF = 2e9;
int T, n, m, s, t, u, v, w;
vector<pair<int, int>> G[N_MAX];
int cost[N_MAX];
bool visit[N_MAX];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> T;
    for (int testcase = 1; testcase <= T; ++testcase) {
        memset(cost, INF, sizeof(cost));
        memset(visit, 0, sizeof(visit));
        for (int i = 0; i < N_MAX; ++i)
            G[i].clear();

        cin >> n >> m >> s >> t;
        for (int i = 0; i < m; ++i) {
            cin >> u >> v >> w;
            G[u].emplace_back(v, w);
            G[v].emplace_back(u, w);
        }
        for (int i = 0; i < n; ++i) {
            for (auto &p : G[i]) {
                dbg("%d %d, ", p.first, p.second);
            }
            dbg("\n");
        }
        dbg("xx\n");

        priority_queue<pair<int, int>> Q;
        Q.push(make_pair(0, s));
        cost[s] = 0;
        while (!Q.empty()) {
            u = Q.top().second;
            Q.pop();
            if (visit[u]) continue;
            visit[u] = 1;
            if (u == t) break;
            for (auto &p : G[u]) {
                v = p.first;
                w = p.second;
                dbg("%d %d %d\n", u, v, w);
                if (cost[v] > cost[u] + w) {
                    cost[v] = cost[u] + w;
                    Q.push(make_pair(-cost[v], v));
                }
            }
        }

        cout << "Case #" << testcase << ": ";
        if (cost[t] == INF) {
            cout << "unreachable\n";
        } else {
            cout << cost[t] << '\n';
        }
    }
    return 0;
}
