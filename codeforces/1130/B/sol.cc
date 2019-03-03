#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    vector<vector<int>> pos(n+1);
    for (int i = 0; i < 2*n; ++i) {
        int x;
        cin >> x;
        pos[x].push_back(i);
    }
    int a = 0, b = 0;
    long long ans = 0;
    for (int i = 1; i <= n; ++i) {
        int x = pos[i][0], y = pos[i][1];
        int v1 = abs(x - a) + abs(y - b);
        int v2 = abs(x - b) + abs(y - a);
        ans += min(v1, v2);
        a = x;
        b = y;
    }
    cout << ans << endl;

    return 0;
}
