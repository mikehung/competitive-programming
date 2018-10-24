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

const int NMAX = 1003;
string board[NMAX];
int visit[NMAX][NMAX];
int dx[8] = {-1, -1, -1, 0, 0, 1, 1, 1};
int dy[8] = {-1, 0, 1, -1, 1, -1, 0, 1};

int main() 
{
    int T, R, C, r, c, x, y, sx, sy, ex, ey;
    cin >> T;
    while (T--) {
        cin >> R >> C;
        memset(visit, -1, sizeof(visit));
        for (r = 0; r < R; ++r) {
            cin >> board[r];
            for (c = 0; c < C; ++c) {
                if (board[r][c] == 'S')
                    sx = r, sy = c;
                if (board[r][c] == 'F')
                    ex = r, ey = c;
            }
        }
        queue<pair<int, int>> Q;
        Q.push(make_pair(sx, sy));
        visit[sx][sy] = 0;
        while (!Q.empty()) {
            r = Q.front().first;
            c = Q.front().second;
            Q.pop();
            if (r == ex && c == ey)
                break;
            for (int i = 0; i < 8; ++i) {
                x = r, y = c;
                while (true) {
                    x += dx[i], y += dy[i];
                    if (x < 0 || y < 0 || x >= R || y >= C || board[x][y] == 'X')
                        break;
                    if (visit[x][y] == -1) {
                        visit[x][y]  = visit[r][c] + 1;
                        Q.push(make_pair(x, y));
                    } else if (visit[x][y] != visit[r][c] + 1) {
                        break;
                    }
                }
            }
        }
        cout << visit[ex][ey] << '\n';
    }
}
