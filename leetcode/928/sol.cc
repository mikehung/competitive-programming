#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    void dfs(int u) {
        for (int v = 0; v < n; ++v) {
            if (G[u][v] && clean.count(v) && !visit.count(v)) {
                visit.insert(v);
                dfs(v);
            }
        }
    }

    int minMalwareSpread(vector<vector<int>>& graph, vector<int>& initial) {
        G = graph;
        n = G.size();
        for (int i = 0; i < n; ++i) {
            clean.insert(i);
        }
        for (auto &u: initial) {
            clean.erase(u);
        }
        vector<vector<int>> infected(n);
        for (auto &u: initial) {
            visit.clear();
            dfs(u);
            for (auto &v: visit) {
                infected[v].push_back(u);
            }
        }
        vector<int> cnt(n);
        for (int u = 0; u < n; ++u) {
            if ((int) infected[u].size() == 1) {
                cnt[infected[u][0]]++;
            }
        }
        int ans = 0, val = -1;
        for (auto &u: initial) {
            if (cnt[u] > val || (cnt[u] == val && u < ans)) {
                ans = u;
                val = cnt[u];
            }
        }
        return ans;
    }
private:
    int n;
    vector<vector<int>> G;
    set<int> clean, visit;
};

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    vector<vector<int>> graph;
    vector<int> initial;

    graph = {{1,1,0},{1,1,0},{0,0,1}}, initial = {0,1};
    assert(0 == Solution().minMalwareSpread(graph, initial));

    graph = {{1,1,0},{1,1,1},{0,1,1}}, initial = {0,1};
    assert(1 == Solution().minMalwareSpread(graph, initial));

    graph = {{1,1,0,0},{1,1,1,0},{0,1,1,1},{0,0,1,1}}, initial = {0,1};
    assert(1 == Solution().minMalwareSpread(graph, initial));

    return 0;
}
