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
    #define debug(args...)  {dbg,args; cerr<<endl;}
#else
    #define debug(args...)  // do nothing
#endif

struct debugger
{
    template<typename T> debugger& operator , (const T& v)
    {
        cerr << v << " ";
        return *this;
    }
} dbg;

int main()
{
    int t, m, n;
    cin >> t;
    while (t--) {
        int x, mx = 1, nx = 1;
        cin >> m >> n;
        --m; --n;
        vector<pair<int, int>> a(m+n);
        for (int i = 0; i < m+n; ++i) {
            cin >> x;
            a[i] = make_pair(x, i);
        }
        sort(a.rbegin(), a.rend());
        long long res = 0;
        for (int i = 0; i < m+n; ++i) {
            if (a[i].second >= m) {
                res += a[i].first * mx;
                ++nx;
            } else {
                res += a[i].first * nx;
                ++mx;
            }
        }
        cout << res << '\n';
    }
}
// Time: O(klogk), Space: O(k), k = m+n
