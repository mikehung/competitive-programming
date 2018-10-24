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

bool overlap(vector<int> &rec1, vector<int> &rec2, vector<int> &rec3)
{
    int x_max = max(rec1[0], rec2[0]);
    int x_min = min(rec1[2], rec2[2]);
    int y_max = max(rec1[1], rec2[1]);
    int y_min = min(rec1[3], rec2[3]);
    if (x_max >= x_min || y_max >= y_min)
        return false;
    rec3 = {x_max, y_max, x_min, y_min};
    return true;
}

int main() 
{
    int n;
    bool first = true;
    cin >> n;
    while (n--) {
        if (!first) {
            cout << '\n';
        }
        first = false;
        vector<int> rec1(4), rec2(4), rec3(4);
        cin >> rec1[0] >> rec1[1] >> rec1[2] >> rec1[3];
        cin >> rec2[0] >> rec2[1] >> rec2[2] >> rec2[3];
        if (overlap(rec1, rec2, rec3)) {
            printf("%d %d %d %d\n", rec3[0], rec3[1], rec3[2], rec3[3]);
        } else {
            printf("No Overlap\n");
        }
    }
}
