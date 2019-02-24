#include <bits/stdc++.h>

using namespace std;

const int MAX = (int) 3e5+11;
int n, a[MAX], all[3], color[MAX][3], ans;
vector<int> g[MAX];

void calc(int p, int u)
{
    color[u][a[u]]++;
    for (auto v: g[u]) if (v != p) {
        calc(u, v);
        for (int i = 0; i < 3; ++i) {
            color[u][i] += color[v][i];
        }
    }
    if (color[u][1] == 0 && color[u][2] == all[2]) ++ans;
    if (color[u][2] == 0 && color[u][1] == all[1]) ++ans;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        all[a[i]]++;
    }
    for (int i = 0; i < n-1; ++i) {
        int u, v;
        cin >> u >> v;
        --u, --v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    calc(-1, 0);
    cout << ans << '\n';

    return 0;
}
