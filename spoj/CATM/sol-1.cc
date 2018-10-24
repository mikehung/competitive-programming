#include <iostream>
#include <iomanip>
#include <string>
#include <sstream>
#include <fstream>
#include <cassert>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <numeric>
#include <utility>
#include <vector>
#include <queue>
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <bitset>
#include <climits>
using namespace std;

#ifdef DEBUG
    #define dbg(...) fprintf(stderr, __VA_ARGS__)
#else
    #define dbg(...)
#endif

const int MAX = 105, INF = 10000;
int R, C, T, a[MAX][MAX];
int mx, my, c1x, c1y, c2x, c2y;

void bfs(int x, int y)
{
    int r, c;
    queue<pair<int, int>> Q;
    Q.push({x, y});
    a[x][y] = 0;
    while (!Q.empty()) {
        x = Q.front().first;
        y = Q.front().second;
        for (int i = 0; i < 4; ++i) {
            r = x + dx[i], c = y + dy[i];
            if (r < 1 || r > R || c < 1 || c > C || a[r][c] < a[x][y]+1)
                continue;
            a[r][c] = a[x][y]+1;
            Q.push({r, c});
        }
    }
}

bool check(int x, int y)
{
    int d = abs(x-mx) + abs(y-my);
    return a[x][y] > d;
}

int main()
{
    cin >> R >> C;
    cin >> T;
    while (T--) {
        cin >> mx >> my >> c1x >> c1y >> c2x >> c2y;
        for (int i = 0; i < MAX; ++i)
            for (int j = 0; j < MAX; ++j)
                a[i][j] = INF;
        bfs(c1x, c1y);
        bfs(c2x, c2y);
        if (check(1, my) || check(R, my) || check(mx, 1) || check(mx, C))
            puts("YES");
        else
            puts("NO");
    }
}
// Time: O(), Space: O()
