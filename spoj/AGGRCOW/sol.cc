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

int t, N, C;

bool F(const vector<int> &a, int c, int x)
{
    auto it = a.begin();
    while (c--) {
        debug(x, *it);
        it = lower_bound(next(it), a.end(), *it+x);
        if (it == a.end())
            return false;
    }
    return true;
}

int main() 
{
    cin >> t;
    while (t--) {
        debug("case ", t);
        cin >> N >> C;
        vector<int> a(N);
        --C;
        for (int i = 0; i < N; ++i)
            cin >> a[i];
        sort(a.begin(), a.end());
        int lo = 0, hi = a.back()-a.front();
        while (lo < hi) {
            int mid = (lo+hi+1)/2;
            if (F(a, C, mid)) {
                lo = mid;
            } else {
                hi = mid-1;
            }
        }
        cout << lo << '\n';
    }
}
