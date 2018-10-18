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
    long long n;
    cin >> n;
    vector<int> a;
    while (n) {
        if (n%10 >= 5)
            a.push_back(9-n%10);
        else
            a.push_back(n%10);
        n /= 10;
    }
    if (a.back() == 0) a.back() = 9;
    int i = a.size()-1;
    while (i >= 0) cout << a[i--];
    cout << '\n';
}
