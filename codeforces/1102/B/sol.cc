#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    map<int, vector<int>> m;
    int n, k, sz = 0;
    cin >> n >> k;
    for (int i = 0; i < n; ++i) {
        int x;
        cin >> x;
        m[x].push_back(i);
        sz = max(sz, (int) m[x].size());
    }
    for (auto &kv: m) {
        cerr << kv.first << ": ";
        for (auto &x: kv.second) cerr << x << ' '; cerr << '\n';
    }
    if (sz > k) {
        cout << "NO\n";
        return 0;
    }
    cout << "YES\n";
    vector<int> ans(n);
    int color = 1;
    for (auto &kv: m) {
        for (auto &x: kv.second) {
            ans[x] = color++;
            if (color > k) color = 1;
        }
    }
    for (auto &x: ans) cout << x << ' '; cout << '\n';

    return 0;
}
