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

int N;

double E(int cnt)
{
    return sqrt(3*N*(N-1)/(double)cnt);
}

int gcd(int a, int b)
{
    if (!b) return a;
    return gcd(b, a%b);
}

int main() 
{
    while (cin >> N) {
        if (!N) return 0;
        vector<int> a(N);
        for (int i = 0; i < N; ++i) {
           cin >> a[i]; 
        }
        int cnt = 0;
        for (int i = 0; i < N; ++i) {
            for (int j = i+1; j < N; ++j) {
                if (gcd(a[i], a[j]) == 1)
                    ++cnt;
            }
        }
        if (!cnt)
            cout << "No estimate for this data set.\n";
        else
            cout << fixed << setprecision(6) << E(cnt) << '\n';
    }
}
