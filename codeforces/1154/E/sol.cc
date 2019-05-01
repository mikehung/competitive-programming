#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, k;
    cin >> n >> k;
    vector<int> an(n);
    vector<pair<int, int>> a(n);
    set<int> s;
    for (int i = 0; i < n; ++i) {
        int x;
        cin >> x;
        a[i] = make_pair(x, i);
        s.insert(i);
    }
    int team = 1, cnt;
    set<int>::iterator it;
    sort(a.rbegin(), a.rend());
    for (int i = 0; i < n; ++i) {
        int idx = a[i].second;
        if (an[idx]) continue;
        vector<int> add = {idx};
        an[idx] = team;
        
        it = s.find(idx);
        cnt = 0;
        while (cnt++ < k && it != s.begin()) {
            it = prev(it);
            add.push_back(*it);
            an[*it] = team;
        }

        it = s.find(idx);
        cnt = 0;
        while (cnt++ < k && next(it) != s.end()) {
            it = next(it);
            add.push_back(*it);
            an[*it] = team;
        }

        for (auto v: add) s.erase(v);
        team = 3 - team;
    }
    for (int i = 0; i < n; ++i) cout << an[i]; cout << endl;
    return 0;
}
