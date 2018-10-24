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

const int NMAX = 66;
string s;
long long cache[NMAX][NMAX];

long long solve(int i, int j)
{
    if (i == j) return 1;
    if (i > j) return 0;
    if (cache[i][j]) return cache[i][j];
    long long ans = 0;
    if (s[i] == s[j])
        ans = solve(i+1, j) + solve(i, j-1) + 1LL;
    else
        ans = solve(i+1, j) + solve(i, j-1) - solve(i+1, j-1);
    return cache[i][j] = ans;
}

int main()
{
    int n;
    cin >> n;
    while (n--) {
        cin >> s;
        for (int i = 0; i < NMAX; ++i)
            memset(cache[i], 0, sizeof(cache[i]));
        cout << solve(0, s.size()-1) << '\n';
    }
}
// Time: O(), Space: O()
