#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, ans = 0, a = 0, b = 0;
    vector<pair<int, int>> t({{0, 0}});
    cin >> n;
    while (n--) {
        int x, y;
        cin >> x >> y;
        if (x == a && y == b) continue;
        if (min(x, y) >= max(a, b)) {
            t.push_back({max(a, b), min(x, y)});
        }
        a = x;
        b = y;
    }
    vector<pair<int, int>> u;
    for (auto &[a, b]: t) {
        if (u.empty() || u.back().second != a) u.push_back({a, b});
        else u.back().second = b;
    }
    for (auto &[a, b]: u) {
        // cerr << a << ' ' << b << endl;
        ans += b - a + 1;
    }
    cout << ans << endl;
    return 0;
}
