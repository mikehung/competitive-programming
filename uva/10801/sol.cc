#include <bits/stdc++.h>
using namespace std;

#ifdef DEBUG
    #define dbg(...) fprintf(stderr, __VA_ARGS__)
#else
    #define dbg(...)
#endif

const int N_MAX = 8, E_MAX = 105, INF = 1e6;
int n, k, t[N_MAX];
set<int> floors[N_MAX];
int dist[N_MAX][E_MAX], visit[N_MAX][E_MAX];

int main()
{
    string line;
    while (cin >> n >> k) {
        for (int i = 0; i < n; ++i) {
            cin >> t[i];
            floors[i].clear();
            memset(dist[i], INF, sizeof(dist[i]));
            memset(visit[i], 0, sizeof(visit[i]));
        }
        cin.ignore();
        for (int i = 0; i < n; ++i) {
            getline(cin, line);
            istringstream iss(line);
            int f;
            while (iss >> f) {
                floors[i].insert(f);
            }
        }
        // cerr << n << ' ' << k << '\n';
        // for (int i = 0; i < n; ++i) {
        //     for (auto x : floors[i])
        //         cerr << x << ' ';
        //     cerr << '\n';
        // }
        priority_queue<tuple<int, int, int>> Q;
        int w, f, e, f1;
        for (int i = 0; i < n; ++i) {
            if (*floors[i].begin() == 0) {
                Q.push(make_tuple(0, 0, i));
                dist[i][0] = 0;
            }
        }
        while (!Q.empty()) {
            tie(w, f, e) = Q.top();
            Q.pop();
            if (visit[e][f]) continue;
            visit[e][f] = 1;
            auto it1 = floors[e].find(f);
            auto it2 = it1;
            if (it1 != floors[e].begin()) {
                f1 = *--it1;
                if (dist[e][f1] > dist[e][f] + abs(f-f1) * t[e]) {
                    dist[e][f1] = dist[e][f] + abs(f-f1) * t[e];
                    Q.push(make_tuple(-dist[e][f1], f1, e));
                }
            }
            if (++it2 != floors[e].end()) {
                f1 = *it2;
                if (dist[e][f1] > dist[e][f] + abs(f-f1) * t[e]) {
                    dist[e][f1] = dist[e][f] + abs(f-f1) * t[e];
                    Q.push(make_tuple(-dist[e][f1], f1, e));
                }
            }
            for (int i = 0; i < n; ++i) {
                if (i == e) continue;
                if (floors[i].count(f) && dist[i][f] > dist[e][f] + 60) {
                    dist[i][f] = dist[e][f] + 60;
                    Q.push(make_tuple(-dist[i][f], f, i));
                }
            }
        }
        int ans = INF;
        for (int i = 0; i < n; ++i) {
            ans = min(ans, dist[i][k]);
        }
        if (ans == INF) {
            cout << "IMPOSSIBLE\n";
        } else {
            cout << ans << '\n';
        }
    }
    return 0;
}
