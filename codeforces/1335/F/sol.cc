#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int tt;
    cin >> tt;
    while (tt--) {
        int r, c;
        cin >> r >> c;
        vector<string> co(r), di(r);
        for (auto &it: co) cin >> it;
        for (auto &it: di) cin >> it;
        int rc = r * c;
        int logrc = 1;
        while ((1<<logrc) < rc) ++logrc;
        vector<vector<int>> dp = vector<vector<int>>(rc, vector<int>(logrc+1));
        for (int i = 0; i < r; ++i) {
            for (int j = 0; j < c; ++j) {
                int v = i*c+j, ni, nj;
                if (di[i][j] == 'U') ni = i-1, nj = j;
                else if (di[i][j] == 'D') ni = i+1, nj = j;
                else if (di[i][j] == 'L') ni = i, nj = j-1;
                else ni = i, nj = j+1;
                int nv = ni*c+nj;
                dp[v][0] = nv;
            }
        }

        for (int deg = 1; deg < logrc+1; ++deg) {
            for (int v = 0; v < rc; ++v) {
                dp[v][deg] = dp[dp[v][deg-1]][deg-1];
            }
        }

        vector<vector<bool>> all(r, vector<bool>(c)), blk(r, vector<bool>(c));
        for (int v = 0; v < rc; ++v) {
            int nv = v;
            for (int deg = 0; deg < logrc+1; ++deg) {
                if ((rc >> deg) & 1) {
                    nv = dp[nv][deg];
                }
            }
            all[nv/c][nv%c] = true;
            if (co[v/c][v%c] == '0') {
                blk[nv/c][nv%c] = true;
            }
        }

        int an1 = 0, an2 = 0;
        for (int i = 0; i < r; ++i) {
            for (int j = 0; j < c; ++j) {
                if (all[i][j]) ++an1;
                if (blk[i][j]) ++an2;
            }
        }
        cout << an1 << ' ' << an2 << '\n';
    }
    return 0;
}
