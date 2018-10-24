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

int N, M;

long long C(int n, int m)
{
    long long res = 1;
    debug(n, m);
    for (int i = 1; i <= m; ++i)
        res = res * (n-i+1) / i;
    return res;
}

int main() 
{
    while (cin >> N >> M) {
        if (N == 0 && M == 0)
            return 0;
        printf("%d things taken %d at a time is %lld exactly.\n", N, M, C(N, min(M, N-M)));
    }
}
