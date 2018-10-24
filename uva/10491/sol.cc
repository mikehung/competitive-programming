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
    double cow, car, show, all;
    while (cin >> cow >> car >> show) {
        all = cow + car;
        cout << fixed << setprecision(5) << 
            (car*cow+car*(car-1))/(all * (all-show-1)) << '\n';
    }
}
// Time: O(1), Space: O(1)
