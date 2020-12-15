#include <bits/stdc++.h>

using namespace std;
using ll = long long;

const int M = 1e9+7;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, m;
    cin >> n >> m;
    vector<vector<ll>> right(n+1, vector<ll>(m+1));
    vector<vector<ll>> down(n+1, vector<ll>(m+1));
    vector<vector<ll>> diag(n+1, vector<ll>(m+1));
    vector<vector<ll>> cnt(n+1, vector<ll>(m+1));
    vector<string> board(n);
    for (auto &it: board) cin >> it;

    right[1][1] = down[1][1] = diag[1][1] = cnt[1][1] = 1;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) if (i != 0 || j != 0) {
            cnt[i+1][j+1] = (right[i+1][j] + down[i][j+1] + diag[i][j]) % M;
            if (board[i][j] == '.') {
                right[i+1][j+1] = (cnt[i+1][j+1] + right[i+1][j]) % M;
                down[i+1][j+1] = (cnt[i+1][j+1] + down[i][j+1]) % M;
                diag[i+1][j+1] = (cnt[i+1][j+1] + diag[i][j]) % M;
            }
        }
    }
    cout << cnt[n][m] << '\n';
    return 0;
}
