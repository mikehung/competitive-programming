#include <bits/stdc++.h>

using namespace std;

int m, n;
vector<int> a, b;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> m;
    for (int i = 0; i < n; ++i) {
        int x;
        cin >> x;
        a.push_back(x);
    }
    for (int i = 0; i < m; ++i) {
        int x;
        cin >> x;
        b.push_back(x);
    }
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    int ans = max(2*a.front(), a.back());
    if (ans < b.front()) {
        cout << ans << '\n';
    } else {
        cout << -1 << '\n';
    }
    return 0;
}
