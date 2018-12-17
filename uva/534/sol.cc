#include <bits/stdc++.h>

using namespace std;

const int MAX = 203;
int n, g[MAX][MAX];
bool visit[MAX];
pair<int, int> points[MAX];

void dfs(int u, int d)
{
    if (visit[u]) return;
    visit[u] = true;
    for (int v = 0; v <= n; ++v) if (u != v) {
        if (g[u][v] <= d) {
            dfs(v, d);
        }
    }
}

bool can(int d)
{
    for (int i = 0; i < n; ++i) visit[i] = false;
    dfs(0, d);
    return visit[1];
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout << fixed << setprecision(3);
    int t = 1;
    while (cin >> n && n) {
        for (int i = 0; i < n; ++i) {
            cin >> points[i].first >> points[i].second;
        }
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < i; ++j) {
                int d1 = points[i].first - points[j].first;
                int d2 = points[i].second - points[j].second;
                g[i][j] = g[j][i] = d1 * d1 + d2 * d2;
            }
        }
        int lo = 0, hi = 1000*1000, mid;
        while (lo < hi) {
            mid = lo + (hi - lo) / 2;
            if (can(mid)) {
                hi = mid;
            } else {
                lo = mid + 1;
            }
        }
        cout << "Scenario #" << t++ << "\nFrog Distance = " << sqrt(lo) << "\n\n";
    }
    return 0;
}
