#include <bits/stdc++.h>

using namespace std;

const int MAX = (int) 2e5+11;
int n, k, u, v;
map<pair<int, int>, int> e;
vector<int> g[MAX], city, finish;
vector<pair<int, int>> cnt;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> k;
    city.resize(n-1);
    finish.resize(n);
    for (int i = 0; i < n-1; ++i) {
        cin >> u >> v;
        if (u > v) swap(u, v);
        e[{u, v}] = i;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    for (int i = 1; i <= n; ++i) {
        cnt.emplace_back(g[i].size(), i);
    }
    sort(cnt.rbegin(), cnt.rend());
    int sz = cnt[k].first;
    for (int i = k; i < n; ++i) {
        queue<int> q;
        q.push(cnt[i].second);
        while (q.size()) {
            u = q.front();
            q.pop();
            if (finish[u]) continue;
            finish[u] = 1;

            vector<bool> ok(sz+1);
            for (auto v: g[u]) {
                if (g[v].size() <= sz && !finish[v]) q.push(v);
                auto par = u < v ? make_pair(u, v) : make_pair(v, u);
                if (city[e[par]] != 0) ok[city[e[par]]] = 1;
            }
            int co = 1;
            for (auto v: g[u]) {
                auto par = u < v ? make_pair(u, v) : make_pair(v, u);
                if (city[e[par]] == 0) {
                    while (ok[co]) ++co;
                    city[e[par]] = co;
                    ok[co] = 1;
                }
            }
        }
    }
    cout << sz << endl;
    for (int i = 0; i < n-1; ++i) cout << (city[i] ? city[i] : 1) << ' ';
    cout << endl;
    return 0;
}
