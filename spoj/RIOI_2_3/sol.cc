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

const int NMAX = 51;
int A[NMAX][NMAX];
bool visit[NMAX][NMAX][1025];
int dir[5] = {0, 1, 0, -1, 0};

int main() 
{
    int T, N, r, c, x, y, sx, sy, ex, ey, mask, nmask;
    cin >> T;
    while (T--) {
        memset(A, 0, sizeof(A));
        memset(visit, 0, sizeof(visit));
        cin >> N;
        for (r = 0; r < N; ++r) {
            for (c = 0; c < N; ++c) {
                cin >> A[r][c];
            }
        }
        cin >> sx >> sy >> ex >> ey;
        queue<tuple<int, int, int>> Q;
        mask = 1<<A[sx][sy];
        Q.push(make_tuple(sx, sy, mask));
        visit[sx][sy][mask] = true;
        while (!Q.empty()) {
            tie(r, c, mask) = Q.front();
            Q.pop();
            for (int i = 0; i < 4; ++i) {
                x = r + dir[i], y = c + dir[i+1];
                if (x < 0 || x >= N || y < 0 || y >= N)
                    continue;
                nmask = mask | (1<<A[x][y]);
                if (visit[x][y][nmask])
                    continue;
                visit[x][y][nmask] = true;
                Q.push(make_tuple(x, y, nmask));
            }
        }
        int ans = 100, cnt, b;
        for (mask = 0; mask < 1024; ++mask) {
            if (visit[ex][ey][mask]) {
                cnt = 0;
                b = mask;
                while (b) {
                    ++cnt;
                    b &= (b-1);
                }
                ans = min(ans, cnt);
            }
        }
        cout << ans << '\n';
    }
}
