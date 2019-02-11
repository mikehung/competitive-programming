#include <bits/stdc++.h>

using namespace std;

const int MAX = (int) 2e5+11;
int n, m, par[MAX], rnk[MAX];
vector<tuple<int, int, int>> edges;

int find(int x)
{
    if (x != par[x]) par[x] = find(par[x]);
    return par[x];
}

int merge(int x, int y)
{
    x = find(x), y = find(y);
    if (x != y) {
        if (rnk[x] < rnk[y]) swap(x, y);
        par[y] = x;
        if (rnk[x] == rnk[y]) ++rnk[x];
        return 1;
    }
    return 0;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    for (int i = 0; i < MAX; ++i) par[i] = i;
    cin >> n >> m;
    for (int i = 0; i < m; ++i) {
        int u, v, w;
        cin >> u >> v >> w;
        edges.push_back(make_tuple(w, u, v));
    }
    sort(edges.begin(), edges.end());
    int i = 0, ans = 0, cnt = 0;
    while (cnt != n-1) {
        int u0, u1, v0, v1, w0, w1, exp_cnt = 0, real_cnt = 0;
        tie(w0, u0, v0) = edges[i];
        for (int j = i; j < m; ++j) {
            tie(w1, u1, v1) = edges[j];
            if (w0 != w1) break;
            if (find(u1) != find(v1)) ++exp_cnt;
        }
        for (int j = i; j < m; ++j, ++i) {
            tie(w1, u1, v1) = edges[j];
            if (w0 != w1) break;
            if (merge(u1, v1)) ++real_cnt, ++cnt;
        }
        ans += exp_cnt - real_cnt;
    }
    cout << ans << endl;
    return 0;
}
