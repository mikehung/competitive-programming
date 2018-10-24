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

int R, C, T;
int mx, my, c1x, c1y, c2x, c2y, d1x, d1y, d2x, d2y;

bool check(int x, int y)
{
    int dm = abs(x-mx) + abs(y-my);
    int d1c = abs(x-c1x) + abs(y-c1y);
    int d2c = abs(x-c2x) + abs(y-c2y);
    if ((d1c <= dm && (d1c-dm) % 2 == 0) || (d2c <= dm && (d2c-dm) % 2 == 0))
        return false;
    return true;
}

int main()
{
    cin >> R >> C;
    cin >> T;
    while (T--) {
        cin >> mx >> my >> c1x >> c1y >> c2x >> c2y;
        if (check(mx, 1) || check(mx, C) || check(1, my) || check(R, my))
            puts("YES");
        else
            puts("NO");
    }
}
