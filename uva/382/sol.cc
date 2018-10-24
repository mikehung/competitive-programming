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
    int n;
    const char *s[3] = {"DEFICIENT", "PERFECT", "ABUNDANT"};
    printf("PERFECTION OUTPUT\n");
    while (scanf("%d", &n)) {
        if (!n) break;
        int val = 1, r, i;
        for (i = 2; i*i < n; ++i) {
            if (n % i == 0) {
                val += i;
                val += n/i;
            }
        }
        if (i*i == n) val += i;
        if (n == 1 || val < n) r = 0;
        else if (val == n) r = 1;
        else r = 2;
        printf("%5d  %s\n", n, s[r]);
    }
    printf("END OF OUTPUT\n");
}
// Time: O(), Space: O()
