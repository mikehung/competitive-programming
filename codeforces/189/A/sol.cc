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
    #define dbg(...)
#endif

const int NMAX = 4000 + 5;
bool cut[NMAX];
int cnt[NMAX];

int main()
{
    int n, a, b, c;
    cin >> n >> a >> b >> c;
    set<int> S;
    S.insert(a);
    S.insert(b);
    S.insert(c);
    cut[0] = true;
    for (int i = 0; i < n; ++i) {
        if (cut[i]) {
            for (auto x : S) {
                if (x + i <= n) {
                    cut[x+i] = true;
                    cnt[x+i] = max(cnt[x+i], cnt[i] + 1);
                }
            }
        }
    }
    cout << cnt[n] << '\n';

    return 0;
}
// Time: O(), Space: O()
