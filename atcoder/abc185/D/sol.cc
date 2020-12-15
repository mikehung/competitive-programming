#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, m;
    cin >> n >> m;
    vector<int> a(m);
    for (auto &it: a) cin >> it;
    if (m == 0) {
        cout << 1 << '\n';
        return 0;
    }

    sort(a.begin(), a.end());
    vector<int> b;
    int pre = 1;
    for (auto cur: a) {
        if (cur-pre > 0) b.push_back(cur-pre);
        pre = cur+1;
    }
    if (n+1-pre > 0) b.push_back(n+1-pre);
    if (b.empty()) {
        cout << 0 << '\n';
        return 0;
    }

    int sz = *min_element(b.begin(), b.end());
    int cnt = 0;
    for (auto x: b) {
        cnt += (x+sz-1) / sz;
    }
    cout << cnt << '\n';
    return 0;
}
