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

long long N, M, m;

bool check(int m, int cnt)
{
    int n = N;
    while (cnt > 0 && n/m) {
        cnt -= n/m;
        n /= m;
    }
    return cnt <= 0;
}

int main()
{
    while (scanf("%lld %lld", &N, &M) == 2) {
        if (M <= 1) {
            printf("%lld divides %lld!\n", M, N);
            continue;
        }
        int cnt = 0;
        bool flag = true;
        m = M;
        while (m % 2 == 0) {
            m /= 2;
            ++cnt;
        }
        if (!check(2, cnt))
            flag = false;
        for (long long i = 3; i*i <= (long long) m && flag; i += 2) {
            cnt = 0;
            while (m % i == 0) {
                m /= i;
                ++cnt;
            }
            if (!check(i, cnt))
                flag = false;
        }
        if (flag && m > 1 && !check(m, 1))
            flag = false;
        if (flag)
            printf("%lld divides %lld!\n", M, N);
        else
            printf("%lld does not divide %lld!\n", M, N);
    }
}
// Time: O(), Space: O()
