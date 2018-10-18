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


int get_ap(vector<int> &v)
{
    if (v.size() == 1)
        return 0;
    int diff = v[1] - v[0];
    bool is_ap = true;
    for (int i = 2; i < v.size(); ++i) {
        if (diff != v[i] - v[i-1]) {
            is_ap = false;
            break;
        }
    }
    if (!is_ap)
        return -1;
    else
        return diff;
}

int main()
{
    int n, x;
    cin >> n;
    map<int, vector<int>> indices;
    vector<pair<int, int>> res;
    for (int i = 0; i < n; ++i) {
        cin >> x;
        indices[x].push_back(i);
    }
    int cnt = 0, ap;
    for (auto kv : indices) {
        ap = get_ap(kv.second);
        if (ap != -1) {
            res.push_back({kv.first, ap});
            ++cnt;
        }
    }
    cout << cnt << '\n';
    for (auto &kv : res) {
        cout << kv.first << ' ' << kv.second << '\n';
    }
}
