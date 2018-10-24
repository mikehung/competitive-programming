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
    int n, carry = 0, val, va, vb;
    string a, b;
    cin >> n;
    while (n--) {
        cin >> a >> b;
        string c;
        carry = 0;
        for (int i = 0; i < max(a.size(), b.size()); ++i) {
            va = i < a.size() ? a[i]-'0' : 0;
            vb = i < b.size() ? b[i]-'0' : 0;
            val = va + vb + carry;
            c += (val % 10) + '0';
            carry = val / 10;
        }
        if (carry) c += carry + '0';
        int j = 0;
        while (j < c.size() && c[j] == '0') ++j;
        if (j == c.size()) cout << 0;
        else {
            while (j < c.size()) {
                cout << c[j++];
            }
        }
        cout << '\n';
    }
}
