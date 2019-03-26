#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, m;
    cin >> n >> m;
    vector<pair<int, int>> v;
    for (int i = 0; i < n; ++i) {
        int a, b;
        cin >> a >> b;
        v.push_back(make_pair(a, b));
    }
    sort(v.begin(), v.end());
    long long ans = 0;
    for (int i = 0; i < n && m; ++i) {
        int cnt = min(m, v[i].second);
        ans += 1ll * v[i].first * cnt;
        m -= cnt;
    }
    cout << ans << endl;
    return 0;
}
