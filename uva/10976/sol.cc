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

int main()
{
    int k;
    while (scanf("%d", &k) == 1) {
        vector<pair<int, int>> ans;
        for (int y = k+1; y <= 2*k; ++y) {
            if ((k*y)%(y-k) == 0)
                ans.push_back(make_pair((k*y)/(y-k), y));
        }
        printf("%zu\n", ans.size());
        for (auto &par : ans)
            printf("1/%d = 1/%d + 1/%d\n", k, par.first, par.second);
    }
}
// Time: O(), Space: O()
