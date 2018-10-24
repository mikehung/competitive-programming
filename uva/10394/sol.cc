#include <iostream>
#include <iomanip>
#include <string>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <utility>
#include <vector>
#include <queue>
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>
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

const int MAXN = 20000002;

int main() 
{
    vector<bool> Prime(MAXN, true);
    vector<int> twins;
    Prime[0] = Prime[1] = false;
    for (long long i = 3; i < MAXN; i += 2) {
        if (Prime[i]) {
            if (Prime[i-2]) twins.push_back(i-2);
            for (long long j = i*i; j < MAXN; j += i) {
                Prime[j] = false;
            }
        }
    }
    int n;
    while (cin >> n) {
        printf("(%d, %d)\n", twins[n-1], twins[n-1]+2);
    }
}
