#include <bits/stdc++.h>

using namespace std;

int n, m, d, cn, cntt;
vector<int> a;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> m >> d;
    for (int r = 0; r < n; ++r) for (int c = 0; c < m; ++c) {
        int x;
        cin >> x;
        a.push_back(x);
    }
    sort(a.begin(), a.end());
    int sz = n * m;
    int mid = a[sz/2];
    for (int i = 0; i < sz; ++i) {
        int diff = abs(mid - a[i]);
        if (diff % d) {
            cout << -1 << '\n';
            return 0;
        }
        cnt += diff / d;
    }
    cout << cnt << '\n';
    return 0;
}
