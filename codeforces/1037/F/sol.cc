#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <vector>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <queue>
#include <ctime>
#include <cassert>
#include <complex>
#include <string>
#include <cstring>
using namespace std;

#ifdef DEBUG
    #define dbg(...) fprintf(stderr, __VA_ARGS__)
#else
    #define eprintf(...)
#endif

typedef long long ll;
typedef pair<int, int> pii;

const int MOD = 1e9 + 7;
int n, k;
ll ans, v;

int main()
{
    scanf("%d %d", &n, &k);
    vector<int> a(n);
    for (int i = 0; i < n; ++i)
        scanf("%d", &a[i]);

    while (!a.empty()) {
        deque<int> Q;
        vector<int> b;
        int i;
        for (i = 0; i < k-1; ++i) {
            while (!Q.empty() && Q.back() < a[i])
                Q.pop_back();
            Q.push_back(a[i]);
        }

        for (; i < a.size(); ++i) {
            while (!Q.empty() && Q.back() < a[i])
                Q.pop_back();
            Q.push_back(a[i]);
            v = Q.front();
            ans = (ans + v) % MOD;
            b.push_back(v);
            if (v == a[i-k+1])
                Q.pop_front();
        }
        swap(a, b);
    }
    printf("%lld\n", ans);

    return 0;
}
// Time: O(), Space: O()
