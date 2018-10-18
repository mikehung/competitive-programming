#include <bits/stdc++.h>
using namespace std;

#ifdef DEBUG
    #define dbg(...) fprintf(stderr, __VA_ARGS__)
#else
    #define dbg(...)
#endif

#define x first
#define y second

typedef pair<int, int> pii;
const int N_MAX = 13, V_MAX = 333, INF = (int) 1e5, SZ = 8;
int n;
pii ans, pos[N_MAX*N_MAX], dp[N_MAX*N_MAX][3], dis[V_MAX][V_MAX];
vector<int> dx = {2, 2, -2, -2, 1, -1, 1, -1};
vector<int> dy = {1, -1, 1, -1, 2, 2, -2, -2};

pii pmin(const pii &p1, const pii &p2)
{
    if (p1.x < p2.x || (p1.x == p2.x && p1.y < p2.y))
        return p1;
    else
        return p2;
}

pii padd(const pii &p1, const pii &p2)
{
    return make_pair(p1.x+p2.x, p1.y+p2.y);
}

int get(int x, int y, int p)
{
    return 3*n*x + 3*y + p;
}

bool in(int x, int y)
{
    return 0 <= x && x < n && 0 <= y && y < n;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n;
    for (int x = 0; x < n; ++x) {
        for (int y = 0; y < n; ++y) {
            int p;
            cin >> p;
            pos[p-1] = make_pair(x, y);
        }
    }
    for (int x = 0; x < V_MAX; ++x) for (int y = 0; y < V_MAX; ++y) {
        if (x == y)
            dis[x][x] = make_pair(0, 0);
        else
            dis[x][y] = make_pair(INF, INF);
    }
    for (int i = 0; i < N_MAX*N_MAX; ++i) for (int p = 0; p < 3; ++p) {
        dp[i][p] = make_pair(INF, INF);
    }
    int nx, ny;
    for (int x = 0; x < n; ++x) for (int y = 0; y < n; ++y) {
        // 0: knight
        for (int i = 0; i < SZ; ++i) {
            nx = x + dx[i], ny = y + dy[i];
            if (in(nx, ny)) {
                dis[get(x, y, 0)][get(nx, ny, 0)] = make_pair(1, 0);
            }
        }

        // 1: bishop
        for (int i = -n; i <= n; ++i) {
            nx = x + i;
            ny = y + i;
            if (in(nx, ny)) {
                dis[get(x, y, 1)][get(nx, ny, 1)] = make_pair(1, 0);
            }
            ny = y - i;
            if (in(nx, ny)) {
                dis[get(x, y, 1)][get(nx, ny, 1)] = make_pair(1, 0);
            }
        }

        // 2. rook
        for (int i = 0; i < n; ++i) {
            nx = x;
            ny = i;
            if (ny != y && in(nx, ny)) {
                dis[get(x, y, 2)][get(nx, ny, 2)] = make_pair(1, 0);
            }
            nx = i;
            ny = y;
            if (nx != x && in(nx, ny)) {
                dis[get(x, y, 2)][get(nx, ny, 2)] = make_pair(1, 0);
            }
        }

        // replace
        for (int p1 = 0; p1 < 3; ++p1) for (int p2 = 0; p2 < 3; ++p2) {
            if (p1 != p2) {
                dis[get(x, y, p1)][get(x, y, p2)] = make_pair(1, 1);
            }
        }
    }
    for (int k = 0; k < 3*n*n; ++k) for (int x = 0; x < 3*n*n; ++x) for (int y = 0; y < 3*n*n; ++y) {
        dis[x][y] = pmin(dis[x][y], padd(dis[x][k], dis[k][y]));
    }
    for (int p = 0; p < 3; ++p)
        dp[0][p] = make_pair(0, 0);
    for (int i = 1; i < n*n; ++i) {
        for (int p1 = 0; p1 < 3; ++p1) for (int p2 = 0; p2 < 3; ++p2) {
            dp[i][p1] = pmin(dp[i][p1], padd(dp[i-1][p2], dis[get(pos[i-1].x, pos[i-1].y, p2)][get(pos[i].x, pos[i].y, p1)]));
        }
    }
    ans = make_pair(INF, INF);
    for (int p = 0; p < 3; ++p)
        ans = pmin(ans, dp[n*n-1][p]);
    cout << ans.x << ' ' << ans.y << '\n';

    return 0;
}
