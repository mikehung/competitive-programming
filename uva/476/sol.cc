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

bool contained(vector<double> &rec, double x, double y)
{
    return rec[0] < x && x < rec[2] && rec[1] < y && y < rec[3];
}

int main() 
{
    vector<vector<double>> recs;
    double a, b, c, d;
    char type;
    while (cin >> type) {
        if (type == '*') break;
        cin >> a >> b >> c >> d;
        recs.push_back({a, d, c, b});
    }
    int p = 0;
    double x, y;
    while (cin >> x >> y) {
        if (x == 9999.9 && y == 9999.9) break;
        bool has = false;
        for (int r = 0; r < recs.size(); ++r) {
            if (contained(recs[r], x, y)) {
                has = true;
                printf("Point %d is contained in figure %d\n", p+1, r+1);
            }
        }
        if (!has)
            printf("Point %d is not contained in any figure\n", p+1);
        ++p;
    }
}
