#include <bits/stdc++.h>

using namespace std;

long long ans, n;

bool check(long long v)
{
    vector<bool> ok(10);
    while (v) {
        ok[v % 10] = 1;
        v /= 10;
    }
    return ok[7] && ok[5] && ok[3];
}

void dfs(long long v)
{
    if (v > n) return;
    if (check(v)) ++ans;
    dfs(v*10+3);
    dfs(v*10+5);
    dfs(v*10+7);
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n;
    dfs(0);
    cout << ans << endl;
    return 0;
}
