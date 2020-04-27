#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, m;
    cin >> n >> m;
    vector<int> islands(m);
    for (int i = 0; i < m; ++i) cin >> islands[i];
    sort(islands.begin(), islands.end());
    int green, red;
    cin >> green >> red;

    vector<vector<int>> dist(m+1, vector<int>(green+1, -1));
    vector<pair<int, int>> q;
    dist[0][0] = 0;
    q.push_back({0, 0});
    while (q.size()) {
        for (int qi = 0; qi < q.size(); ++qi) {
            int i = q[qi].first, t = q[qi].second;
            if (i > 0) {
                int nt = t + islands[i] - islands[i-1];
                if (nt <= green && dist[i-1][nt] == -1) {
                    dist[i-1][nt] = dist[i][t];
                    q.push_back({i-1, nt});
                }
            }
            if (i < m-1) {
                int nt = t + islands[i+1] - islands[i];
                if (nt <= green && dist[i+1][nt] == -1) {
                    dist[i+1][nt] = dist[i][t];
                    q.push_back({i+1, nt});
                }
            }
        }

        vector<pair<int, int>> nq;
        for (int qi = 0; qi < q.size(); ++qi) {
            int i = q[qi].first, t = q[qi].second;
            if (t == green && dist[i][0] == -1) {
                dist[i][0] = dist[i][t] + 1;
                nq.push_back({i, 0});
            }
        }
        swap(q, nq);
    }
    long long an = 1e18;
    for (int g = 0; g <= green; ++g) {
        if (dist[m-1][g] != -1) {
            long long cur = 1ll * (green + red) * dist[m-1][g] + g;
            an = min(an, cur);
        }
    }
    if (an == 1e18) an = -1;
    cout << an << '\n';

    return 0;
}
