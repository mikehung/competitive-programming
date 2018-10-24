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
    int i = 1;
    long long a, b;
    while (scanf("%lld %lld", &a, &b) && (a || b))
        printf("Case %d: %lld\n", i++, (b*(b-1LL)/2LL) * (a*(a-1L)/2LL));
}
// Time: O(), Space: O()
