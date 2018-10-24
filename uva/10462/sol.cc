#include <bits/stdc++.h>
using namespace std;

#ifdef DEBUG
    #define dbg(...) fprintf(stderr, __VA_ARGS__)
#else
    #define dbg(...)
#endif

struct Edge {
    int cost, u, v;
    Edge() {}
};

const int V_MAX = 105;
int Parent[V_MAX], Rank[V_MAX];
int T, V, E;

void init()
{
    for (int i = 0; i < V_MAX; ++i) {
        Parent[i] = i;
        Rank[i] = 0;
    }
}

int find(int x)
{
    if (Parent[x] != x) {
        Parent[x] = find(Parent[x]);
    }
    return Parent[x];
}

bool merge(int x, int y)
{
    x = find(x);
    y = find(y);
    if (x != y) {
        if (Rank[x] < Rank[y])
            swap(x, y);
        Parent[y] = x;
        if (Rank[x] == Rank[y])
            ++Rank[x];
        return true;
    }
    return false;
}

bool cmp(const Edge &e1, const Edge &e2)
{
    return e1.cost < e2.cost;
}

int main()
{
    Edge edge;
    scanf("%d", &T);
    for (int t = 1; t <= T; ++t) {
        scanf("%d %d", &V, &E);
        vector<Edge> edges;
        for (int i = 0; i < E; ++i) {
            scanf("%d %d %d", &edge.u, &edge.v, &edge.cost);
            edges.push_back(edge);
        }
        sort(edges.begin(), edges.end(), cmp);
        init();
        vector<int> mst;
        for (int i = 0; i < E; ++i) {
            edge = edges[i];
            if (merge(edge.u, edge.v)) {
                mst.push_back(i);
            }
        }
        printf("Case #%d : ", t);
        if (mst.size() != V-1) {
            printf("No way\n");
            continue;
        }
        int sec_cost = INT_MAX;
        for (int mst_i : mst) {
            init();
            int cost = 0, sz = 0;
            for (int i = 0; i < E; ++i) {
                if (i == mst_i) continue;
                edge = edges[i];
                if (merge(edge.u, edge.v)) {
                    ++sz;
                    cost += edge.cost;
                }
            }
            if (sz == V-1) {
                sec_cost = min(sec_cost, cost);
            }
        }
        if (sec_cost == INT_MAX) {
            printf("No second way\n");
        } else {
            printf("%d\n", sec_cost);
        }
    }
    return 0;
}
