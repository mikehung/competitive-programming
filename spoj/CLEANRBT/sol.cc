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

const int NMAX = 22, DMAX = 12;
string board[NMAX];
int visit[NMAX][NMAX][1 << DMAX];
int dirty_id[NMAX][NMAX];
int R, C;
int dir[5] = {0, 1, 0, -1, 0};

int main() 
{
    while (cin >> C >> R) {
        if (!R && !C)
            return 0;
        memset(visit, -1, sizeof(visit));
        memset(dirty_id, -1, sizeof(dirty_id));
        int r, c, x, y, sx, sy, steps = -1, dirty_cnt = 0, mask = 0, nxt_mask;
        for (r = 0; r < R; ++r) {
            cin >> board[r];
            for (c = 0; c < C; ++c) {
                if (board[r][c] == 'o') {
                    sx = r, sy = c;
                    board[r][c] = '.';
                }
                if (board[r][c] == '*') {
                    dirty_id[r][c] = dirty_cnt++;
                }
            }
        }
        queue<tuple<int, int, int>> Q;
        visit[sx][sy][mask] = 0;
        Q.push(make_tuple(sx, sy, mask));
        while (!Q.empty()) {
            tie(r, c, mask) = Q.front();
            Q.pop();
            if (mask == ((1 << dirty_cnt)-1)) {
                steps = visit[r][c][mask];
                break;
            }
            for (int i = 0; i < 4; ++i) {
                x = r + dir[i], y = c + dir[i+1];
                if (x < 0 || x >= R || y < 0 || y >= C || board[x][y] == 'x')
                    continue;
                if (board[x][y] == '.') {
                    nxt_mask = mask;
                } else {
                    nxt_mask = mask | (1 << dirty_id[x][y]);
                }
                if (visit[x][y][nxt_mask] != -1)
                    continue;
                visit[x][y][nxt_mask] = visit[r][c][mask] + 1;
                Q.push(make_tuple(x, y, nxt_mask));
            }
        }
        cout << steps << '\n';
    }
}
