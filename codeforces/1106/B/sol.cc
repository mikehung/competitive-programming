#include <bits/stdc++.h>

using namespace std;

const int MAX = (int) 1e5+11;
int n, m, cnt[MAX], cost[MAX], t, d;

bool cmp(int i, int j)
{
    return cost[i] < cost[j] || (cost[i] == cost[j] && i < j);
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> m;
    for (int i = 0; i < n; ++i) cin >> cnt[i+1];
    for (int i = 0; i < n; ++i) cin >> cost[i+1];
    int vi = 0;
    vector<int> v(n);
    for (int i = 0; i < n; ++i) v[i] = i+1;
    sort(v.begin(), v.end(), cmp);
    for (int i = 0; i < m; ++i) {
        long long ans = 0, x;
        cin >> t >> d;
        x = min(d, cnt[t]);
        ans += 1ll * x * cost[t];
        d -= x;
        cnt[t] -= x;
        while (d && vi < n) {
            x = min(d, cnt[v[vi]]);
            ans += 1ll * x * cost[v[vi]];
            d -= x;
            cnt[v[vi]] -= x;
            if (cnt[v[vi]] == 0) ++vi;
        }
        if (d) ans = 0;
        cout << ans << '\n';
    }

    return 0;
}
