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
     #define debug(args...)            {dbg,args; cerr<<endl;}
#else
    #define debug(args...)              // Just strip off all debug tokens
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
    int n, k;
    cin >> n >> k;
    vector<int> a(2*n+2);
    for (int i = 1; i <= 2*n+1; ++i)
        cin >> a[i];
    for (int i = 1; i <= 2*n+1; ++i) {
        if (i % 2 == 0 && a[i-1] < a[i]-1 && a[i]-1 > a[i+1] && k-- > 0) {
            --a[i];
        }
        cout << a[i] << ' ';
    }
    cout << '\n';
}
