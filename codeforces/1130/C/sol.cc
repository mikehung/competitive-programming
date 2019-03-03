#include <bits/stdc++.h>

using namespace std;

int n, r1, c1, r2, c2, ans = INT_MAX;
vector<string> g;
vector<vector<int>> pos;

void dfs(int r, int c, char ch)
{
    if (r < 0 || r >= n || c < 0 || c >= n || g[r][c] != '0') return;
    g[r][c] = ch;
    if (ch == '3') {
        pos.push_back({r, c});
    }
    dfs(r+1, c, ch);
    dfs(r-1, c, ch);
    dfs(r, c+1, ch);
    dfs(r, c-1, ch);
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n;
    cin >> r1 >> c1 >> r2 >> c2;
    --r1, --c1, --r2, --c2;
    g.resize(n);
    for (auto &s: g) cin >> s;
    dfs(r1, c1, '2');
    if (g[r2][c2] == '2') {
        cout << 0 << endl;
        return 0;
    }
    dfs(r2, c2, '3');
    for (int r = 0; r < n; ++r) for (int c = 0; c < n; ++c) if (g[r][c] == '2') {
        for (auto &p: pos) {
            int x = p[0], y = p[1];
            ans = min(ans, (x-r)*(x-r)+(y-c)*(y-c));
        }
    }
    cout << ans << endl;

    return 0;
}
