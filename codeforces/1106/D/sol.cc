#include <bits/stdc++.h>

using namespace std;

const int MAX = (int) 1e5+11;
int n, m, visit[MAX];
vector<int> g[MAX];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> m;
    for (int i = 0; i < m; ++i) {
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    priority_queue<int, vector<int>, greater<int>> q;
    q.push(1);
    visit[1] = true;
    while (q.size()) {
        int u = q.top();
        q.pop();
        cout << u << ' ';
        for (auto v: g[u]) if (!visit[v]) {
            q.push(v);
            visit[v] = true;
        }
    }
    cout << endl;
    return 0;
}
