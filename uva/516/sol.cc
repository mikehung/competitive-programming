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

int main()
{
    string line;
    while (getline(cin, line) && line.size() > 1) {
        ll n = 1, a, b;
        istringstream iss(line);
        while (iss >> a >> b)
            n *= pow(a, b);
        --n;
        vector<pair<ll, int>> factors;
        int cnt = 0;
        while (n % 2 == 0) {
            n /= 2;
            ++cnt;
        }
        if (cnt)
            factors.push_back(make_pair(2, cnt));
        for (ll i = 3; i*i <= n; ++i) {
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
        for (int i = factors.size()-1; i >= 0; --i) {
            printf("%lld %d", factors[i].first, factors[i].second);
            if (i) printf(" ");
        }
        printf("\n");
    }
}
// Time: O(), Space: O()
