#include <bits/stdc++.h>
using namespace std;

#ifdef DEBUG
    #define dbg(...) fprintf(stderr, __VA_ARGS__)
#else
    #define dbg(...)
#endif

const int X_MAX = 105, C_MAX = 13;
int cnt[C_MAX][X_MAX][X_MAX];
int N, Q, C, x, y, s, t;

struct Point {
    int x, y;
} p1, p2;

int sol()
{
    int ans = 0;
    for (int c = 0; c <= C; ++c) {
        ans += ((c+t) % (C+1)) * (cnt[c][p2.x][p2.y] - cnt[c][p1.x-1][p2.y] - cnt[c][p2.x][p1.y-1] + cnt[c][p1.x-1][p1.y-1]);
    }
    return ans;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> N >> Q >> C;
    for (int i = 0; i < N; ++i) {
        cin >> x >> y >> s;
        cnt[s][x][y]++;
    }
    for (int c = 0; c <= C; ++c) {
        for (int x = 1; x < X_MAX; ++x) {
            for (int y = 1; y < X_MAX; ++y) {
                cnt[c][x][y] += cnt[c][x-1][y] + cnt[c][x][y-1] - cnt[c][x-1][y-1];
            }
        }
    }
    while (Q--) {
        cin >> t >> p1.x >> p1.y >> p2.x >> p2.y;
        cout << sol() << '\n';
    }
    return 0;
}
// Time: O(N + C*X_MAX*X_MAX + Q*C), Space: O(C*X_MAX*X_MAX)
