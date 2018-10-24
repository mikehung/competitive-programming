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
    int n, idx;
    int factors[10000];
    while (scanf("%d", &n)) {
        if (n == 0) return 0;
        idx = 0;
        printf("%d =", n);
        if (n < 0)
            factors[idx++] = -1;
        while (n % 2 == 0) {
            n /= 2;
            factors[idx++] = 2;
        }
        if (n < 0)
            n *= -1;
        for (long long i = 3; i * i <= n; ++i) {
            while (n % i == 0) {
                n /= i;
                factors[idx++] = i;
            }
        }
        if (n > 1)
            factors[idx++] = n;
        for (int i = 0; i < idx; ++i) {
            printf(" %d", factors[i]);
            if (i != idx-1)
                printf(" x");
        }
        printf("\n");
    }
}
// Time: O(), Space: O()
