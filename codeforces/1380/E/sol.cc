#include <bits/stdc++.h>

using namespace std;

int get_diff(const vector<int> &a, int i)
{
    int an = 0;
    if (i > 0 && a[i] != a[i-1]) ++an;
    if (i < a.size()-1 && a[i] != a[i+1]) ++an;
    return an;
}

int find(const vector<int> &p, int x)
{
    if (x != p[x]) {
        x = find(p, p[x]);
    }
    return p[x];
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, m, an = 0;
    cin >> n >> m;

    vector<int> a(n);
    vector<vector<int>> pos(m);
    for (int i = 0; i < n; ++i) {
        int x;
        cin >> x;
        --x;
        a[i] = x;
        pos[x].push_back(i);
        if (i != 0 && a[i] != a[i-1]) ++an;
    }

    vector<int> par(m);
    for (int i = 0; i < m; ++i) par[i] = i;

    cout << an << '\n';
    for (int r = 0; r < m-1; ++r) {
        int x, y;
        cin >> x >> y;
        --x, --y;
        x = find(par, x), y = find(par, y);
        if (pos[x].size() < pos[y].size()) {
            swap(x, y);
        }

        // move disc y to disc x
        par[y] = x;
        for (auto i: pos[y]) {
            an -= get_diff(a, i);
            pos[x].push_back(i);
            a[i] = x;
            an += get_diff(a, i);
        }
        pos[y].clear();
        cout << an << '\n';
    }
    return 0;
}
