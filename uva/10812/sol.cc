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
    int t, sum, diff, a, b;
    cin >> t;
    while (t--) {
        cin >> sum >> diff;
        if ((sum + diff) % 2 || (sum - diff) % 2 || sum < diff) {
            cout << "impossible\n";
        } else {
            a = (sum + diff) / 2;
            b = (sum - diff) / 2;
            cout << a << ' ' << b << '\n';
        }
    }
}
