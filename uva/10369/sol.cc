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
    #define debug(args...)    { dbg,args; cerr << endl; }
#else
    #define debug(args...)    // do nothing
#endif

struct debugger
{
    template<typename T> debugger& operator , (const T& v)
    {    
        cerr << v << ' ';
        return *this;
    }
} dbg;

struct Point {
    int x, y, s;
};

struct Edge {
    double cost;
    int u, v;
};

static const int X = 555;
int T, S, N;
Point P[X];
Edge E[X*X/2], MST[X];
int Par[X], Rank[X];

double get_cost(int i, int j)
{
    return sqrt((P[i].x-P[j].x)*(P[i].x-P[j].x) + (P[i].y-P[j].y)*(P[i].y-P[j].y));
}

bool cmp(const Edge &e1, const Edge &e2)
{
    return e1.cost < e2.cost;
}

void init()
{
    for (int i = 0; i < N; ++i) {
        Par[i] = i;
        Rank[i] = 0;
    }
}

int find(int x)
{
    if (Par[x] != x)
        Par[x] = find(Par[x]);
    return Par[x];
}

int merge(int x, int y)
{
    x = find(x), y = find(y);
    if (x != y) {
        if (Rank[x] < Rank[y])
            swap(x, y);
        Par[y] = x;
        if (Rank[x] == Rank[y])
            ++Rank[x];
        return 1;
    }
    return 0;
}

int main() 
{
    cin >> T;
    while (T--) {
        cin >> S >> N;
        init();
        for (int i = 0; i < N; ++i) {
            cin >> P[i].x >> P[i].y;
            P[i].s = 0;
        }
        int e = 0;
        for (int i = 0; i < N; ++i) {
            for (int j = 0; j < i; ++j) {
                E[e].cost = get_cost(i, j);
                E[e].u = i;
                E[e].v = j;
                ++e;
            }
        }
        sort(E, E+e, cmp);
        int u, v, m = 0;
        e = 0;
        while (m != N-1) {
            u = E[e].u, v = E[e].v;
            if (merge(u, v)) {
                MST[m++] = E[e];
            }
            ++e;
        }
        cout << fixed << setprecision(2) << MST[m-S].cost << '\n';
    }
}
