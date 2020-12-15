#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, k;
    cin >> n >> k;
    vector<vector<int>> adj(n, vector<int>(n));
    for (int i = 0; i < n; ++i) for (int j = 0; j < n; ++j) {
        cin >> adj[i][j];
    }
    vector<int> seq;
    for (int i = 1; i < n; ++i) {
        seq.push_back(i);
    }

    int cnt = 0;
    do {
        int cost = 0, u = 0;
        for (auto v: seq) {
            cost += adj[u][v];
            u = v;
        }
        cost += adj[u][0];
        if (cost == k) ++cnt;
    } while (next_permutation(seq.begin(), seq.end()));

    cout << cnt << '\n';
    return 0;
}
