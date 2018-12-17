#include <bits/stdc++.h>

using namespace std;

const int N = 5;
vector<vector<int>> perms, happy(N, vector<int>(N));
vector<bool> visit(N);

void dfs(vector<int> &cur)
{
    if (N == (int) cur.size()) {
        perms.push_back(cur);
        return;
    }
    for (int i = 0; i < N; ++i) {
        if (visit[i]) continue;
        cur.push_back(i);
        visit[i] = true;
        dfs(cur);
        visit[i] = false;
        cur.pop_back();
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    vector<int> cur;
    dfs(cur);
    for (int i = 0; i < N; ++i) for (int j = 0; j < N; ++j)
        cin >> happy[i][j];
    int mx = 0;
    for (auto &perm: perms) {
        int a = 0;
        for (int i = 0; i < N; ++i) {
            for (int j = i+1; j < N; j += 2) {
                a += happy[perm[j]][perm[j-1]] + happy[perm[j-1]][perm[j]];
            }
        }
        mx = max(mx, a);
    }
    cout << mx << '\n';
    return 0;
}
