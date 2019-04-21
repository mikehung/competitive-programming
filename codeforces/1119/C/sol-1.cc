#include <bits/stdc++.h>

using namespace std;
map<int, set<int>> mp;

void bye()
{
    cout << "No\n";
    exit(0);
}

void calc(int x1, int y1, int y2)
{
    int x2 = -1, f1 = -1;
    for (auto &kv: mp) if (kv.first != x1) {
        if (kv.second.count(y1) && kv.second.count(y2)) {
            x2 = kv.first;
            break;
        } else if (kv.second.count(y1) || kv.second.count(y2)) {
            f1 = kv.first;
        }
    }
    if (x2 != -1) {
        mp[x1].erase(y1);
        mp[x1].erase(y2);
        if (mp[x1].empty()) mp.erase(x1);
        mp[x2].erase(y1);
        mp[x2].erase(y2);
        if (mp[x2].empty()) mp.erase(x2);
    } else if (f1 != -1) {
        mp[x1].erase(y1);
        mp[x1].erase(y2);
        if (mp[x1].empty()) mp.erase(x1);
        if (mp[f1].count(y1)) {
            mp[f1].erase(y1);
            mp[f1].insert(y2);
        } else {
            mp[f1].erase(y2);
            mp[f1].insert(y1);
        }
    } else {
        bye();
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, m;
    cin >> n >> m;
    vector<vector<int>> a(n, vector<int>(m));
    for (int r = 0; r < n; ++r) for (int c = 0; c < m; ++c) {
        cin >> a[r][c];
    }
    int x;
    vector<pair<int, int>> pnts;
    for (int r = 0; r < n; ++r) for (int c = 0; c < m; ++c) {
        cin >> x;
        if (x != a[r][c]) {
            mp[r].insert(c);
            pnts.push_back(make_pair(r, c));
        }
    }
    while (mp.size()) {
        int x1 = -1;
        for (auto &kv: mp) if (kv.second.size() > 1) {
            x1 = kv.first;
            break;
        }
        if (x1 == -1) bye();
        auto it = mp[x1].begin();
        calc(x1, *it, *next(it));
    }
    cout << "Yes\n";
    return 0;
}
