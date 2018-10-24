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
    int n, cnt;
    while (scanf("%d", &n)) {
        if (!n) return 0;
        printf("%d : ", n);
        cnt = 0;
        if (n % 2 == 0) {
            ++cnt;
            while (n % 2 == 0) n /= 2;
        }
        for (int i = 3; i * i <= n; i += 2) {
            if (n % i == 0) {
                ++cnt;
                while (n % i == 0) n /= i;
            }
        }
        if (n > 1) ++cnt;
        printf("%d\n", cnt);
    }
}
// Time: O(), Space: O()
