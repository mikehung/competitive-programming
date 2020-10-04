#include <bits/stdc++.h>

using namespace std;
using ll = long long;

struct Point {
    int x, y;
};

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, m;
    cin >> n >> m;
    vector<Point> a(n), b(m);
    for (int i = 0; i < n; ++i) {
        cin >> a[i].x >> a[i].y;
    }
    for (int i = 0; i < m; ++i) {
        cin >> b[i].x >> b[i].y;
    }

    const int MX = 1e6+11;
    vector<int> all_y(MX);
    map<int, vector<int>> mp;
    for (int i = 0; i < n; ++i) for (int j = 0; j < m; ++j) {
        if (a[i].x <= b[j].x && a[i].y <= b[j].y) {
            int need_x = b[j].x-a[i].x+1;
            int need_y = b[j].y-a[i].y+1;
            mp[need_x].push_back(need_y);
            all_y[need_y]++;
        }
    }
    if (mp.empty()) {
        cout << 0 << '\n';
        return 0;
    }

    int j = MX-1;
    while (j > 0 && all_y[j] == 0) --j;

    int an = j;
    for (auto &kv: mp) {
        int need_x = kv.first;
        for (int v: kv.second) {
            all_y[v]--;
        }
        while (j > 0 && all_y[j] == 0) --j;
        an = min(an, need_x+j);
    }
    cout << an << '\n';
    return 0;
}
