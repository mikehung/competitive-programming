#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    const int N = 400, INF = 1e9;
    int tt;
    cin >> tt;
    while (tt--) {
        int n;
        cin >> n;
        vector<int> a(n);
        for (auto &it: a) cin >> it;
        sort(a.begin(), a.end());

        vector<vector<int>> vals(n+1, vector<int>(N));
        vector<vector<int>> mins(n+1, vector<int>(N));
        for (int i = 0; i < n; ++i) {
            mins[i+1][i] = INF;
            for (int j = i+1; j < N; ++j) {
                vals[i+1][j] = mins[i][j-1] + abs(j-a[i]);
                mins[i+1][j] = min(mins[i+1][j-1], vals[i+1][j]);
            }
        }
        cout << mins[n][N-1] << '\n';
    }
    return 0;
}
