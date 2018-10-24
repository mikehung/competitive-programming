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
    string s;
    int X_cnt, O_cnt;
    bool X_win, O_win, valid;
    while (cin >> s) {
        if (s == "end") break;
        valid = X_win = O_win = false;
        X_cnt = count(s.begin(), s.end(), 'X');
        O_cnt = count(s.begin(), s.end(), 'O');
        for (int i = 0; i < 3; ++i) {
            if (s[3*i] == 'O' && s[3*i+1] == 'O' && s[3*i+2] == 'O')
                O_win = true;
            if (s[3*i] == 'X' && s[3*i+1] == 'X' && s[3*i+2] == 'X')
                X_win = true;
            if (s[i] == 'O' && s[i+3] == 'O' && s[i+6] == 'O')
                O_win = true;
            if (s[i] == 'X' && s[i+3] == 'X' && s[i+6] == 'X')
                X_win = true;
        }
        if (s[0] == 'O' && s[4] == 'O' && s[8] == 'O')
            O_win = true;
        if (s[2] == 'O' && s[4] == 'O' && s[6] == 'O')
            O_win = true;
        if (s[0] == 'X' && s[4] == 'X' && s[8] == 'X')
            X_win = true;
        if (s[2] == 'X' && s[4] == 'X' && s[6] == 'X')
            X_win = true;
        if (X_win && O_win)
            valid = false;
        else if (X_win)
            valid = X_cnt == O_cnt+1;
        else if (O_win)
            valid = X_cnt == O_cnt;
        else
            valid = (X_cnt == 5 && O_cnt == 4);
        if (valid)
            cout << "valid\n";
        else
            cout << "invalid\n";
    }
}
