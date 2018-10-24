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

const int NMAX = 102;
string s, t;
int dp[NMAX][NMAX];

int LCS(int i, int j)
{
    if (i == s.size() || j == t.size())
        return 0;
    int ans, c1, c2;

    if (dp[i][j] != -1)
        return dp[i][j];
    if (s[i] == t[j])
        ans = LCS(i+1, j+1) + 1;
    else {
        c1 = LCS(i+1, j);
        c2 = LCS(i, j+1);
        ans = max(c1, c2);
    }
    return dp[i][j] = ans;
}

int main() 
{
    int i = 1;
    for (;; ++i) {
        getline(cin, s);
        if (s.size() > 0 && s[0] == '#')
            return 0;
        getline(cin, t);
        memset(dp, -1, sizeof(dp));
        printf("Case #%d: you can visit at most %d cities.\n", i, LCS(0, 0));
    }
}
