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

typedef long long ll;
int k;
ll n, p;

bool is_prime(int n)
{
    for (ll i = 2; i*i <= n; ++i)
        if (n % i == 0)
            return false;
    return true;
}

int main()
{
    while (scanf("%d", &k)) {
        if (!k) break;
        n = pow(2, k) - 1;
        p = pow(2, k-1) * n;
        if (is_prime(n))
            printf("Perfect: %lld!\n", p);
        else if (is_prime(k))
            puts("Given number is prime. But, NO perfect number is available.");
        else
            puts("Given number is NOT prime! NO perfect number is available.");
    }
}
// Time: O(), Space: O()
