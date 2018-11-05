#include <bits/stdc++.h>

using namespace std;

const int N = 2e5 + 123;
int n, cost[N], a[N], color[N];
long long ans;

int find(int x)
{
    int c = cost[x];
    int y = a[x];
    while (y != x) {
        c = min(c, cost[y]);
        y = a[y];
    }
    return c;
}

int dfs(int x)
{
    int c = 0;
    color[x] = 1;
    if (color[a[x]] == 0)
        c = dfs(a[x]);
    else if (color[a[x]] == 1)  // find cycle
        c = find(x);
    color[x] = 2;
    return c;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> cost[i];
    }
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
    }
    for (int i = 1; i <= n; ++i) {
        if (color[i] == 0) {
            ans += dfs(i);
        }
    }
    cout << ans << '\n';
    return 0;
}
