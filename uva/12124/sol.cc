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

typedef long long ll;

ll get_price(int q, map<string, map<ll, ll>> &comps)
{
    ll b = 0;
    for (auto &kv : comps) {
        auto it = kv.second.lower_bound(q);
        if (it == kv.second.end()) {
            b = -1;
            break;
        } else {
            b += it->second;
        }
    }
    return b;
}

int main() 
{
    int T, N, B;
    string type, drop;
    ll price, quality;
    cin >> T;
    while (T--) {
        cin >> N >> B;
        map<string, map<ll, ll>> comps;
        for (int i = 0; i < N; ++i) {
            cin >> type >> drop >> price >> quality;
            if (comps[type].count(quality)) {
                comps[type][quality] = min(comps[type][quality], price);
            } else {
                comps[type][quality] = price;
            }
        }
        for (auto &kv : comps) {
            map<ll, ll> items;
            for (auto i_it = kv.second.begin(); i_it != kv.second.end(); ++i_it) {
                bool flag = true;
                for (auto j_it = next(i_it); j_it != kv.second.end(); ++j_it) {
                    if (i_it->second >= j_it->second)
                        flag = false;
                }
                if (flag)
                    items[i_it->first] = i_it->second;
            }
            kv.second = items;
        }
        ll lo = 0, hi = 1000000000, mid, b;
        while (lo < hi) {
            mid = lo + (hi - lo + 1) / 2;
            b = get_price(mid, comps);
            if (b == -1 || b > B) {
                hi = mid - 1;
            } else {
                lo = mid;
            }
        }
        cout << lo << '\n';
    }
}
