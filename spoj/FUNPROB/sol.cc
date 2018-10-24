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
#include <complex>
using namespace std;

#ifdef DEBUG
    #define dbg(...) fprintf(stderr, __VA_ARGS__)
#else
    #define dbg(...)
#endif

int main()
{
    int N, M;
    double ans;
    while (cin >> N >> M) {
        if (!N && !M) break;
        if (N > M)
            ans = 0.;
        else if (!N)
            ans = 1.;
        else
            ans = (double) (M - N + 1) / (M + 1);
        cout << fixed << setprecision(6) << ans << '\n';
    }
}
// Time: O(), Space: O()
