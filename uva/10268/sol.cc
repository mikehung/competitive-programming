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
        cerr << v <<" ";
        return *this;
    }
} dbg;

int main()
{
    long long x, y, c, ans;
    string s;
    while (cin >> x) {
        cin.ignore();
        getline(cin, s);
        istringstream iss(s);
        vector<long long> coef;
        while (iss >> c)
            coef.push_back(c);
        ans = 0;
        y = 1;
        int n = coef.size();
        for (long long i = 1; i < n; ++i) {
            ans += i * coef[n-i-1] * y;
            y *= x;
        }
        cout << ans << '\n';
    }
}
