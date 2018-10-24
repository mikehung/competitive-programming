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
#include <climits>
using namespace std;

#ifdef DEBUG
    #define dbg(...) fprintf(stderr, __VA_ARGS__)
#else
    #define dbg(...)
#endif

const int CMAX = 5005;
int C, R;
map<string, int> ids;
map<int, set<int>> G;
int Parent[CMAX], Rank[CMAX], Count[CMAX];

int find(int u)
{
    if (u != Parent[u])
        Parent[u] = find(Parent[u]);
    return Parent[u];
}

bool merge(int u, int v)
{
    u = find(u), v = find(v);
    if (u != v) {
        if (Rank[u] < Rank[v])
            swap(u, v);
        Parent[v] = u;
        Count[u] += Count[v];
        if (Rank[u] == Rank[v])
            ++Rank[u];
        return true;
    }
    return false;
}

int main()
{
    int id1, id2;
    string name, name1, name2;
    while (cin >> C >> R && (C || R)) {
        ids.clear();
        G.clear();
        for (int i = 0; i < C; ++i) {
            cin >> name;
            Parent[i] = i;
            Rank[i] = 0;
            Count[i] = 1;
            ids[name] = i;
        }
        for (int i = 0; i < R; ++i) {
            cin >> name2 >> name1;
            id1 = ids[name1];
            id2 = ids[name2];
            merge(id1, id2);
        }
        int ans = 1;
        for (int i = 0; i < C; ++i)
            ans = max(ans, Count[i]);
        cout << ans << '\n';
    }
}
// Time: O(), Space: O()
