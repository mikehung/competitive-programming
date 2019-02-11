#include <bits/stdc++.h>

using namespace std;

const int MAX = (int) 1e5+11, MMAX = 321;
int n, m, a[MAX], l[MMAX], r[MMAX];
vector<int> add[MAX], sub[MAX];

void update(int lo, int hi, int v)
{
    for (int i = lo; i <= hi; ++i) a[i] += v;
}

int get()
{
    int mx = a[1], mn = a[1];
    for (int i = 1; i <= n; ++i) {
        if (mx < a[i]) mx = a[i];
        if (mn > a[i]) mn = a[i];
    }
    return mx - mn;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> m;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
    }
    for (int i = 1; i <= m; ++i) {
        cin >> l[i] >> r[i];
        if (l[i] != 1) {
            sub[1].push_back(i);
            add[l[i]].push_back(i);
        }
        sub[r[i]+1].push_back(i);
    }

    int ans = 0, resi;
    for (int i = 1; i <= n; ++i) {
        for (auto j: sub[i]) update(l[j], r[j], -1);
        for (auto j: add[i]) update(l[j], r[j], 1);
        if (i == 1 || sub[i].size() || add[i].size()) {
            int cur = get();
            if (ans < cur) {
                ans = cur;
                resi = i;
            }
        }
    }

    vector<int> res;
    for (int i = 1; i <= m; ++i) {
        if (!(l[i] <= resi && resi <= r[i])) {
            res.push_back(i);
        }
    }
    cout << ans << endl << res.size() << endl;
    for (auto x: res) cout << x << ' ';
    cout << endl;

    return 0;
}
