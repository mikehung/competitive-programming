#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    vector<int> a(n+1, -1);
    vector<vector<int>> vec;
    for (int i = 0; i < n-1; ++i) {
        int u, v;
        cin >> u >> v;
        if (a[u] == -1 && a[v] == -1) {
            a[u] = a[v] = vec.size();
            vec.push_back({u, v});
        } else if (a[u] == -1) {
            vec[a[v]].push_back(u);
            a[u] = a[v];
        } else if (a[v] == -1) {
            vec[a[u]].push_back(v);
            a[v] = a[u];
        } else {
            if (vec[a[u]].size() < vec[a[v]].size()) swap(u, v);
            for (auto w: vec[a[v]]) {
                a[w] = a[u];
                vec[a[u]].push_back(w);
            }
        }
    }
    for (auto &vv: vec) if (vv.size() == n) {
        for (auto &x: vv) cout << x << ' ';
        cout << endl;
    }
    return 0;
}
