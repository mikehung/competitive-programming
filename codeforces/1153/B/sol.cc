#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, m, h;
    cin >> n >> m >> h;
    vector<int> a(m), b(n);
    for (auto &v: a) cin >> v;
    for (auto &v: b) cin >> v;
    for (int r = 0; r < n; ++r) {
        for (int c = 0; c < m; ++c) {
            int x;
            cin >> x;
            if (x == 0) cout << 0 << ' ';
            else cout << min(a[c], b[r]) << ' ';
        }
        cout << endl;
    }
    return 0;
}
