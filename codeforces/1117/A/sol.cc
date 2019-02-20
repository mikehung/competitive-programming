#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, mx = 0;
    cin >> n;
    vector<int> a(n);
    for (auto &v: a) {
        cin >> v;
        mx = max(mx, v);
    }
    int res = 0, cur = 0;
    for (auto &v: a) {
        if (v == mx) {
            cur++;
        } else {
            cur = 0;
        }
        res = max(res, cur);
    }
    cout << res << '\n';
    return 0;
}
