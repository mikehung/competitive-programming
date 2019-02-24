#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, m;
    cin >> n >> m;
    vector<int> a(n);
    for (auto &v: a) {
        cin >> v;
    }
    sort(a.rbegin(), a.rend());
    for (int day = 1; day <= n; ++day) {
        int cnt = 0;
        for (int i = 0; i < n; ++i) {
            cnt += max(0, a[i] - i/day);
        }
        if (cnt >= m) {
            cout << day << '\n';
            return 0;
        }
    }
    cout << -1 << '\n';
    return 0;
}
