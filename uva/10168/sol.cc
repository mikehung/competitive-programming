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

const int MAXN = 10000002;

bool check(vector<int> &ans, vector<pair<int, int>> &index1, vector<pair<int, int>> &index2)
{
    int a, b, c, d;
    for (int i = 0; i < index1.size(); ++i) {
        for (int j = 0; j < index2.size(); ++j) {
            a = index1[i].first, b = index1[i].second;
            c = index2[j].first, d = index2[j].second;
            if (a != c && a != d && b != c && b != d) {
                ans = {a, b, c, d};
                return true;
            }
        }
    }
    return false;
}

int main() 
{
    vector<bool> table(MAXN, true);
    vector<int> primes = {2};
    for (long long i = 3; i < MAXN; i += 2) {
        if (table[i]) {
            primes.push_back(i);
            for (long long j = i * i; j < MAXN; j += i) {
                table[j] = false;
            }
        }
    }
    int n;
    while (cin >> n) {
        if (n < 8) {
            printf("Impossible.\n");
            continue;
        }
        int lo = 0, hi = primes.size()-1, x;
        if (n & 1) {
            printf("2 3 ");
            n -= 5;
        } else {
            printf("2 2 ");
            n -= 4;
        }
        while (lo <= hi) {
            x = primes[lo] + primes[hi];
            if (x == n)
                break;
            else if (x < n) {
                ++lo;
            } else {
                --hi;
            }
        }
        printf("%d %d\n", primes[lo], primes[hi]);
    }
}
