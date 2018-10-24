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

const int N = 5;
long long nums[N];
bool used[N];
vector<char> ops = {'+', '-', '*'};

bool bt(int n, long long val)
{
    if (n == N)
        return val == 23;

    long long nval;
    for (int i = 0; i < N; ++i) {
        if (used[i]) continue;
        used[i] = 1;
        if (n == 0) {
            nval = nums[i];
            if (bt(n+1, nval))
                return true;
        } else {
            for (auto op : ops) {
                if (op == '+')
                    nval = val + nums[i];
                else if (op == '-')
                    nval = val - nums[i];
                else if (op == '*')
                    nval = val * nums[i];
                if (bt(n+1, nval))
                    return true;
            }
        }
        used[i] = 0;
    }
    return false;
}

int main() 
{
    while (true) {
        bool all_zero = true;
        for (int i = 0; i < N; ++i) {
            cin >> nums[i];
            if (nums[i])
                all_zero = false;
        }
        if (all_zero)
            return 0;
        memset(used, 0, sizeof(used));
        if (bt(0, 0))
            cout << "Possible\n";
        else
            cout << "Impossible\n";
    }
}
