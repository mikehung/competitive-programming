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
    int T, N, P;
    scanf("%d", &T);
    for (int t = 1; t <= T; ++t) {
        scanf("%d", &N);
        P = N;
        vector<int> factors;
        for (long long i = 2; i*i <= N && factors.size() < 2; ++i) {
            while (N % i == 0 && factors.size() < 2) {
                N /= i;
                factors.push_back(i);
            }
        }
        printf("Case #%d: %d", t, P);
        printf(" = %d * %d", factors[0], P / factors[0]);
        printf(" = %d * %d\n", factors[0] * factors[1], P / factors[0] / factors[1]);
    }
}
// Time: O(), Space: O()
