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

const int NMAX = 103, CMAX = 502, MAX = NMAX * CMAX;
int T, N;
bool P[MAX];

int main() 
{
    int p, sum = 0;
    cin >> T;
    while (T--) {
        cin >> N;
        memset(P, 0, sizeof(P));
        sum = 0;
        P[0] = 1;
        for (int i = 1; i <= N; ++i) {
            cin >> p;
            for (int j = sum; j >= 0; --j) {
                if (P[j])
                    P[j+p] = 1;
            }
            sum += p;
        }
        int res = sum;
        for (int i = sum; i >= 0; --i) {
            if (P[i])
                res = min(res, abs(sum-i-i));
        }
        cout << res << '\n';
    }
}
