#include <bits/stdc++.h>

using namespace std;

using Type = pair<long long, int>;
int n, m, k, x, y, w;
map<int, vector<tuple<int, int, int>>> G;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> m >> k;
    vector<long long> dis(n, 1e18);
    vector<int> visit(n), edge(n);
    for (int i = 1; i <= m; ++i) {
        int u, v;
        cin >> u >> v >> w;
        --u, --v;
        G[u].push_back(make_tuple(v, w, i));
        G[v].push_back(make_tuple(u, w, i));
    }
    priority_queue<Type, vector<Type>, greater<Type>> q;
    vector<int> ans;
    dis[0] = 0;
    q.push(make_pair(0, 0));
    while (!q.empty() && ans.size() < k) {
        auto &par = q.top();
        int u = par.second;
        q.pop();
        if (visit[u]) continue;
        visit[u] = true;
        if (u)
            ans.push_back(edge[u]);
        for (auto tup: G[u]) {
            int v, w, i;
            tie(v, w, i) = tup;
            if (dis[v] > dis[u] + w) {
                edge[v] = i;
                dis[v] = dis[u] + w;
                q.push(make_pair(dis[v], v));
            }
        }
    }
    cout << ans.size() << '\n';
    for (auto x: ans)
        cout << x << ' ';
    cout << '\n';

    return 0;
}
