#include <bits/stdc++.h>

using namespace std;
using ll = long long;

const bool MULTI_TESTCASES = 1;

void solve()
{
    int n, m;
    cin >> n;
    vector<int> a(n);
    for (auto &it: a) cin >> it;

    cin >> m;
    vector<int> b(m);
    for (auto &it: b) cin >> it;

    int an = 0, mx = 0, cur = 0;
    for (int i = 0; i < n; ++i) {
        cur += a[i];
        mx = max(mx, cur);
    }
    an += mx;

    cur = mx = 0;
    for (int i = 0; i < m; ++i) {
        cur += b[i];
        mx = max(mx, cur);
    }
    an += mx;
    cout << an << '\n';
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int testcases = 1;
    if (MULTI_TESTCASES) cin >> testcases;
    while (testcases--) solve();
    return 0;
}
