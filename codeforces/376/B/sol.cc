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
        cerr << v <<" ";
        return *this;
    }
} dbg;

int main()
{
    int n, m, a, b, c;
    cin >> n >> m;
    vector<int> people(n+1);
    for (int i = 0; i < m; ++i) {
        cin >> a >> b >> c;
        people[a] -= c;
        people[b] += c;
    }
    int ans = 0;
    for (int c : people) {
        if (c > 0)
            ans += c;
    }
    cout << ans << '\n';
}
