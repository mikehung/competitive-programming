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

tuple<bool, double, double> solve(int x1, int y1, int x2, int y2)
{
    double a = 0, b = 0;
    bool inf = false;
    if (x1 == x2) {
        inf = true;
        a = x1;
    } else {
        a = (double) (y1-y2) / (x1-x2);
        b = y1 - a*x1;
    }
    return make_tuple(inf, a, b);
}

tuple<double, double> inter(double a1, double b1, double a2, double b2)
{
    double x, y;
    x = (b2-b1) / (a1-a2);
    y = a1 * x + b1;
    return make_tuple(x, y);
}

int main() 
{
    printf("INTERSECTING LINES OUTPUT\n");
    int n, x11, y11, x12, y12, x21, y21, x22, y22;
    bool inf1, inf2;
    double x, y, a1, b1, a2, b2;
    cin >> n;
    while (n--) {
        cin >> x11 >> y11 >> x12 >> y12 >> x21 >> y21 >> x22 >> y22;
        tie(inf1, a1, b1) = solve(x11, y11, x12, y12);
        tie(inf2, a2, b2) = solve(x21, y21, x22, y22);
        if (inf1) {
            if (inf2) {
                if (a1 == a2)
                    puts("LINE");
                else
                    puts("NONE");
            } else {
                x = a1;
                y = a2 * x + b2;
                printf("POINT %.2f %.2f\n", x, y);
            }
        } else {
            if (inf2) {
                x = a2;
                y = a1 * x + b1;
                printf("POINT %.2f %.2f\n", x, y);
            } else {
                if (a1 == a2) {
                    if (b1 == b2)
                        puts("LINE");
                    else
                        puts("NONE");
                } else {
                    tie(x, y) = inter(a1, b1, a2, b2);
                    printf("POINT %.2f %.2f\n", x, y);
                }
            }
        }
    }
    printf("END OF OUTPUT\n");
}
