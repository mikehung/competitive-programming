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
#include <complex>
using namespace std;

#ifdef DEBUG
    #define debug(args...)  {dbg,args; cerr<<endl;}
#else
    #define debug(args...)  // do nothing
#endif

struct debugger
{
    template<typename T> debugger& operator , (const T& v)
    {    
        cerr<<v<<" ";    
        return *this;    
    }
} dbg;

int m, n;
vector<int> d = {0, 1, 0, -1, 0};

void bfs(const vector<string> &world, vector<vector<bool>> &visit, char land, int r, int c, int &cnt)
{
    int x, y;
    queue<pair<int, int>> Q;
    Q.push(make_pair(r, c));
    visit[r][c] = true;
    while (!Q.empty()) {
        r = Q.front().first;
        c = Q.front().second;
        Q.pop();
        ++cnt;
        for (int i = 0; i < 4; ++i) {
            x = r + d[i], y = c + d[i+1];
            if (x < 0 || x >= m) continue;
            if (y == -1) y = n-1;
            else if (y == n) y = 0;
            if (world[x][y] == land && !visit[x][y]) {
                visit[x][y] = true;
                Q.push(make_pair(x, y));
            }
        }
    }
}

int main() 
{
    while (cin >> m >> n) {
        int x0, y0;
        vector<string> world(m);
        vector<vector<bool>> visit(m, vector<bool>(n));
        for (int r = 0; r < m; ++r) {
            cin >> world[r];
        }
        cin >> x0 >> y0;
        char land = world[x0][y0];
        int res = 0;
        for (int r = 0; r < m; ++r) {
            for (int c = 0; c < n; ++c) {
                if (world[r][c] == land && !visit[r][c]) {
                    int cnt = 0;
                    bool before = visit[x0][y0];
                    bfs(world, visit, land, r, c, cnt);
                    bool after = visit[x0][y0];
                    if (!before && after) continue;
                    res = max(res, cnt);
                }
            }
        }
        cout << res << '\n';
    }
}
