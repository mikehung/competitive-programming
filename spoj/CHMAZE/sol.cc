#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <vector>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <queue>
#include <ctime>
#include <cassert>
#include <complex>
#include <string>
#include <cstring>
using namespace std;

const int PMAX = 12, NMAX = 22;
int R, C, P, r, c, p, nr, nc, np;
string maze[PMAX][NMAX];
int visit[PMAX][NMAX][NMAX];
int dr[5] = {0, 1, 0, -1, 0};
int dc[5] = {0, 0, 1, 0, -1};

int main()
{
    int testcase = 1;
    while (cin >> R >> C >> P && (R || C || P)) {
        for (p = 0; p < P; ++p) {
            for (r = 0; r < R; ++r) {
                memset(visit[p][r], 0, sizeof(visit[p][r]));
                cin >> maze[p][r];
            }
        }
        bool ok = false;
        queue<tuple<int, int, int>> Q;
        Q.push(make_tuple(0, 0, 0));
        visit[0][0][0] = 1;
        while (!Q.empty() && !ok) {
            tie(p, r, c) = Q.front();
            Q.pop();
            for (int i = 0; i < 5; ++i) {
                np = (p+1) % P;
                nr = r + dr[i];
                nc = c + dc[i];
                if (nr < 0 || nr >= R || nc < 0 || nc >= C) continue;
                if (maze[np][nr][nc] == '1' || visit[np][nr][nc]) continue;
                if (nr == R-1 && nc == C-1) {
                    ok = true;
                    break;
                }
                Q.push(make_tuple(np, nr, nc));
                visit[np][nr][nc] = visit[p][r][c] + 1;
            }
        }
        if (ok)
            printf("Case %d: Luke and Leia can escape in %d steps.\n", testcase++, visit[p][r][c]);
        else
            printf("Case %d: Luke and Leia cannot escape.\n", testcase++);
    }
	return 0;
}
// Time: O(), Space: O()
