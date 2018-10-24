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

const int NMAX = 105;
int T, N, K;
vector<int> ans, cur;
set<int> G[NMAX];
int Color[NMAX];

void dfs(int u)
{
    if (u == N + 1) {
        if (cur.size() > ans.size())
            ans = cur;
        return;
    }

    Color[u] = 1;
    dfs(u+1);

    bool ok = true;
    for (auto v : G[u])
        if (Color[v] == 2)
            ok = false;
    if (!ok) return;

    Color[u] = 2;
    cur.push_back(u);
    dfs(u+1);
    cur.pop_back();
    Color[u] = 0;
}

int main() 
{
    int u, v;
    cin >> T;
    while (T--) {
        cin >> N >> K;
        for (int i = 1; i <= N; ++i)
            G[i].clear();
        ans.clear();
        cur.clear();
        memset(Color, 0, sizeof(Color));
        for (int i = 0; i < K; ++i) {
            cin >> u >> v;
            G[u].insert(v);
            G[v].insert(u);
        }
        dfs(1);
        cout << ans.size() << '\n';
        bool first = true;
        for (auto u : ans) {
            if (!first) cout << ' ';
            first = false;
            cout << u;
        }
        cout << '\n';
    }
}
