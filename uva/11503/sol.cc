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

static const int X = 100123;
int N;
int P[X], R[X], C[X];

void init()
{
    for (int i = 0; i < X; ++i) {
        P[i] = i;
        R[i] = C[i] = 1;
    }
}

int find(int x)
{
    if (P[x] != x)
        P[x] = find(P[x]);
    return P[x];
}

int merge(int x, int y)
{
    x = find(x), y = find(y);
    if (x != y) {
        if (R[x] < R[y])
            swap(x, y);
        P[y] = x;
        C[x] += C[y];
        if (R[x] == R[y])
            ++R[x];
    }
    return C[x];
}

int main()
{
    int T, F, id;
    string s, t;
    cin >> T;
    while (T--) {
        cin >> F;
        id = 0;
        init();
        map<string, int> ids;
        map<string, set<string>> net;
        while (F--) {
            cin >> s >> t;
            net[s].insert(t);
            net[t].insert(s);
            if (ids.find(s) == ids.end())
                ids[s] = id++;
            if (ids.find(t) == ids.end())
                ids[t] = id++;
            cout << merge(ids[s], ids[t]) << '\n';
        }
    }
}
