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

int gcd(int a, int b)
{
    if (!b) return a;
    return gcd(b, a % b);
}

int main()
{
    int n;
    while (scanf("%d", &n) == 1 && n) {
        vector<pair<int, int>> factors;
        int cnt;
        bool negative = n < 0;
        if (n % 2 == 0) {
            cnt = 0;
            while (n % 2 == 0) {
                n /= 2;
                ++cnt;
            }
            factors.push_back(make_pair(2, cnt));
        }
        if (negative) n *= -1;
        for (long long i = 3; i * i <= n; ++i) {
            cnt = 0;
            while (n % i == 0) {
                n /= i;
                ++cnt;
            }
            if (cnt)
                factors.push_back(make_pair(i, cnt));
        }
        if (n > 1)
            factors.push_back(make_pair(n, 1));
        int res = factors[0].second;
        for (int i = 1; i < factors.size(); ++i)
            res = gcd(res, factors[i].second);
        if (negative)
            while (res % 2 == 0) res /= 2;
        printf("%d\n", res);
    }
}
// Time: O(), Space: O()
