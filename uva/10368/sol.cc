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

long long a, b;

void gcd(long long a, long long b, int &w)
{
    if (a < b) swap(a, b);
    if (a%b == 0 || a/b > 1) return;
    w *= -1;
    gcd(b, a%b, w);
}

int main() 
{
    while (cin >> a >> b) {
        if (a == 0 && b == 0)
            return 0;
        int w = 1;
        gcd(a, b, w);
        if (w == 1)
            cout << "Stan wins\n";
        else
            cout << "Ollie wins\n";
    }
}
