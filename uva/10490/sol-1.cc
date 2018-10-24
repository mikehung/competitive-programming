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
ll n, p, sum;
vector<pair<ll, int>> factors;

void dfs(int i, vector<int> &coefs, ll v)
{
    bool less = false;
    for (int i = 0; i < factors.size(); ++i) {
        if (coefs[i] > factors[i].second) return;
        if (coefs[i] < factors[i].second) less = true;
    }
    if (!less) return;
    sum += v;
    ++coefs[i];
    dfs(i, coefs, v * factors[i].first);
    --coefs[i];
    if (i+1 < factors.size()) {
        ++coefs[i+1];
        dfs(i+1, coefs, v * factors[i+1].first);
        --coefs[i+1];
    }
}

bool is_prime(int n)
{
    for (int i = 2; i*i <= n; ++i)
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
        sum = 0;
        factors.clear();

        factors.push_back(make_pair(2, k-1));
        for (ll i = 3; i * i <= n; i += 2) {
            int cnt = 0;
            while (n % i == 0) {
                n /= i;
                ++cnt;
            }
            if (cnt)
                factors.push_back(make_pair(i, cnt));
        }
        if (n > 1)
            factors.push_back(make_pair(n, 1));

        vector<int> coefs(factors.size());
        dfs(0, coefs, 1LL);
        if (sum == p)
            printf("Perfect: %lld!\n", p);
        else if (is_prime(k))
            puts("Given number is prime. But, NO perfect number is available.");
        else
            puts("Given number is NOT prime! NO perfect number is available.");
    }
}
// Time: O(), Space: O()
