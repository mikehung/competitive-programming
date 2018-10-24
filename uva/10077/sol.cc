#ifdef DEBUG
#include "../testlib/testlib.h"
#endif
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

void dbg(const vector<pair<int, int>> &cur)
{
    cerr << "cur:\n";
    for (auto &par : cur) {
        cerr << par.first << '/' << par.second << ' ';
    }
    cerr << '\n';
}

int main() 
{
    int a, b, c, d;
    while (cin >> a >> b) {
        if (a == 1 && b == 1)
            return 0;
        int idx;
        bool flag = false;
        vector<pair<int, int>> cur = {{0, 1}, {1, 0}};
        while (true) {
            vector<pair<int, int>> nxt;
            for (int i = 0; i < cur.size(); ++i) {
                nxt.push_back(cur[i]);
                if (i != cur.size()-1) {
                    c = cur[i].first + cur[i+1].first;
                    d = cur[i].second + cur[i+1].second;
                    nxt.push_back(make_pair(c, d));
                    if (a == c && b == d) {
                        flag = true;
                        idx = nxt.size()-1;
                    }
                }
            }
            swap(cur, nxt);
            if (flag)
                break;
        }
        string ans;
        int lo = 1, hi = cur.size()-2, mid;
        while (lo < hi) {
            mid = lo + (hi-lo)/2;
            if (mid > idx) {
                hi = mid-1;
                ans += "L";
            } else {
                lo = mid+1;
                ans += "R";
            }
        }
        // dbg(cur);
        cout << ans << '\n';
    }
}
