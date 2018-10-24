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
        cerr<<v<<" ";    
        return *this;    
    }
} dbg;

int main() 
{
    int n;
    while (cin >> n) {
        if (n == 0) break;
        int x, y, x0, y0, s = 0, o = 0;
        vector<pair<int, int>> points(n);
        for (int i = 0; i < n; ++i) {
            cin >> x >> y;
            points[i] = make_pair(x, y);
            if (i == n/2) {
                x0 = x;
                y0 = y;
            }
        }
        for (auto &point : points) {
            x = point.first;
            y = point.second;
            if ((x > x0 && y > y0) || (x < x0 && y < y0))
                ++s;
            if ((x < x0 && y > y0) || (x > x0 && y < y0))
                ++o;
        }
        cout << s << ' ' << o << '\n';
    }
}
