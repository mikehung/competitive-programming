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

long long N, ans;
int M;

map<long long, long long> factor(long long n)
{
    map<long long, long long> f;
    while (n % 2 == 0) {
        n /= 2;
        ++f[2];
    }
    for (long long i = 3; i * i <= n; i += 2) {
        while (n % i == 0) {
            n /= i;
            ++f[i];
        }
    }
    if (n > 2)
        ++f[n];
    return f;
}

int main() 
{
    double n;
    int cnt;
    while (cin >> N >> M) {
        vector<long long> nums(M);
        vector<map<long long, long long>> factors(M);
        ans = 0;
        for (int i = 0; i < M; ++i) {
            cin >> nums[i];
            factors[i] = factor(nums[i]);
        }
        for (int i = 0; i < (1<<M); ++i) {
            cnt = 0;
            map<long long, long long> f;
            for (int b = 0; b < 16; ++b) {
                if ((i>>b) & 1) {
                    ++cnt;
                    for (auto &kv : factors[b]) {
                        f[kv.first] = max(f[kv.first], kv.second);
                    }
                }
            }
            n = (double) N;
            for (auto &kv : f) {
                while (kv.second--)
                    n /= (double) kv.first;
            }
            if (cnt & 1)
                ans -= (long long) n;
            else
                ans += (long long) n;
        }
        cout << ans << '\n';
    }
}
