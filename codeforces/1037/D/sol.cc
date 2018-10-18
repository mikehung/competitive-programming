#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <vector>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <queue>
#include <ctime>
#include <cassert>
#include <complex>
#include <string>
#include <cstring>
using namespace std;

#ifdef DEBUG
    #define dbg(...) fprintf(stderr, __VA_ARGS__)
#else
    #define dbg(...)
#endif

typedef long long ll;
typedef pair<int, int> pii;

const int NMAX = 200000 + 5;
map<int, vector<int>> G;
int n, u, v, a[NMAX], idx[NMAX], P[NMAX], D[NMAX];

int main()
{
    scanf("%d", &n);
    for (int i = 0; i < n-1; ++i) {
        scanf("%d %d", &u, &v);
        G[u].push_back(v);
        G[v].push_back(u);
    }

    for (int i = 0; i < n; ++i) {
        scanf("%d", &a[i]);
        idx[a[i]] = i;
    }

    queue<int> Q;
    Q.push(1);
    D[1] = 0;
    P[1] = -1;
    while (!Q.empty()) {
        u = Q.front();
        Q.pop();
        for (auto v : G[u]) {
            if (P[u] != v) {
                Q.push(v);
                P[v] = u;
                D[v] = D[u] + 1;
            }
        }
    }

    for (int i = 1; i < n; ++i) {
        if (D[a[i]] < D[a[i-1]] || idx[P[a[i]]] < idx[P[a[i-1]]]) {
            puts("No");
            return 0;
        }
    }
    puts("Yes");

    return 0;
}
// Time: O(), Space: O()
