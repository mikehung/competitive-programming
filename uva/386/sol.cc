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

const int NMAX = 205;
int cube[NMAX], a[3], C, X, Y;
set<tuple<int, int, int>> ans;

void dfs(int i)
{
    if (a[0] > a[1] || a[1] > a[2])
        return;
    Y = cube[a[0]] + cube[a[1]] + cube[a[2]];
    if (X <= Y) {
        if (X == Y)
            ans.insert(make_tuple(a[0], a[1], a[2]));
        return;
    }
    ++a[i];
    dfs(i);
    --a[i];
    if (i) {
        ++a[i-1];
        dfs(i-1);
        --a[i-1];
    }
}

int main()
{
    for (int i = 0; i < NMAX; ++i)
        cube[i] = pow(i, 3);

    int x, y, z;
    for (C = 1; C <= 200; ++C) {
        ans.clear();
        a[0] = a[1] = a[2] = 2;
        X = cube[C];
        dfs(2);
        for (auto &tup : ans) {
            tie(x, y, z) = tup;
            printf("Cube = %d, Triple = (%d,%d,%d)\n", C, x, y, z);
        }
    }
}
// Time: O(), Space: O()
