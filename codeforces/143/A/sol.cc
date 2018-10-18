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

void get_answers(vector<bool> &visit, vector<vector<int>> &answers, vector<int> ans)
{
    if (ans.size() == 4) {
        answers.push_back(ans);
        return;
    }
    for (int i = 1; i < 10; ++i) {
        if (!visit[i-1]) {
            visit[i-1] = true;
            ans.push_back(i);
            get_answers(visit, answers, ans);
            ans.pop_back();
            visit[i-1] = false;
        }
    }
}

int main() 
{
    int r[2], c[2], d[2];
    cin >> r[0] >> r[1] >> c[0] >> c[1] >> d[0] >> d[1];
    vector<vector<int>> answers;
    vector<bool> visit(10);
    get_answers(visit, answers, {});
    for (auto a : answers) {
        if (r[0] == a[0]+a[1] &&
            r[1] == a[2]+a[3] &&
            c[0] == a[0]+a[2] &&
            c[1] == a[1]+a[3] &&
            d[0] == a[0]+a[3] &&
            d[1] == a[1]+a[2]) {
            cout << a[0] << ' ' << a[1] << '\n';
            cout << a[2] << ' ' << a[3] << '\n';
            return 0;
        }
    }
    cout << -1 << '\n';
}
