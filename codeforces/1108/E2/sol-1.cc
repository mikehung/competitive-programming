#include <bits/stdc++.h>

using namespace std;

const int MAX = (int) 1e5+11, AMAX = (int) 1e6+11;
int n, m, a[MAX], ans[MAX], add[MAX];
pair<int, int> segs[MAX];
vector<int> lf[MAX], rg[MAX];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> m;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    for (int i = 0; i < m; ++i) {
        int l, r;
        cin >> l >> r;
        --l, --r;
        segs[i] = make_pair(l, r);
        lf[r].push_back(l);
        rg[l].push_back(r);
    }

    int mn = AMAX;
    for (int r = 0; r < n; ++r) {
        ans[r] = max(ans[r], a[r] + add[r] - mn);
        for (auto l: lf[r]) {
            for (int j = l; j <= r; ++j) {
                --add[j];
                mn = min(mn, a[j] + add[j]);
            }
        }
        mn = min(mn, a[r] + add[r]);
    }
    mn = AMAX;
    for (int i = 0; i < MAX; ++i) add[i] = 0;
    for (int l = n-1; l >= 0; --l) {
        ans[l] = max(ans[l], a[l] + add[l] - mn);
        for (auto r: rg[l]) {
            for (int j = l; j <= r; ++j) {
                --add[j];
                mn = min(mn, a[j] + add[j]);
            }
        }
        mn = min(mn, a[l] + add[l]);
    }
    int resi = 0;
    for (int i = 0; i < n; ++i) if (ans[resi] < ans[i]) {
        resi = i;
    }
    vector<int> res;
    for (int i = 0; i < m; ++i) {
        if (!(segs[i].first <= resi && resi <= segs[i].second)) {
            res.push_back(i);
        }
    }
    cout << ans[resi] << endl << res.size() << endl;
    for (auto x: res) cout << x+1 << ' ';
    cout << endl;

    return 0;
}
