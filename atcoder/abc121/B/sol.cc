#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, m, c;
    cin >> n >> m >> c;
    vector<int> b(m);
    for (auto &v: b) cin >> v;
    int ans = 0;
    for (int x = 0; x < n; ++x) {
        int val = 0;
        for (int i = 0; i < m; ++i) {
            int a;
            cin >> a;
            val += a * b[i];
        }
        if (val + c > 0) ans++;
    }
    cout << ans << endl;
    return 0;
}
