#include <bits/stdc++.h>
using namespace std;

#ifdef DEBUG
    #define dbg(...) fprintf(stderr, __VA_ARGS__)
#else
    #define dbg(...)
#endif

const int N_MAX = 404;
int n, m;
int d[N_MAX], p[N_MAX];
set<int> train[N_MAX], bus[N_MAX];

void go(set<int> (&car)[N_MAX])
{
    memset(d, -1, sizeof(d));
    queue<int> Q;
    Q.push(1);
    p[1] = -1;
    d[1] = 0;
    while (!Q.empty()) {
        int u = Q.front();
        Q.pop();
        for (auto v : car[u]) {
            if (v == n) {
                cout << d[u] + 1 << '\n';
                return;
            } else if (d[v] == -1) {
                Q.push(v);
                d[v] = d[u] + 1;
                p[v] = u;
            }
        }
    }
    cout << -1 << '\n';
    return;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int u, v;
    cin >> n >> m;
    for (int i = 0; i < m; ++i) {
        cin >> u >> v;
        train[u].insert(v);
        train[v].insert(u);
    }
    for (int u = 1; u <= n; ++u) {
        for (int v = u+1; v <= n; ++v) {
            if (!train[u].count(v)) {
                bus[u].insert(v);
                bus[v].insert(u);
            }
        }
    }
    if (train[1].count(n)) {
        go(bus);
    } else {
        go(train);
    }

    return 0;
}
