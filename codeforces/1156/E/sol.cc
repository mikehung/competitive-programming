#include <bits/stdc++.h>

using namespace std;

const int MAX = (int) 2e5+11;
int n, a[MAX], pos[MAX], lf[MAX], rg[MAX], an;

void calc(int lo, int hi, int pos_lo, int pos_hi, int mx)
{
    for (int i = lo; i < hi; ++i) {
        int x = mx - a[i];
        if (x >= 1 && x <= n && pos[x] >= pos_lo && pos[x] < pos_hi) {
            ++an;
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        pos[a[i]] = i;
    }

    vector<pair<int, int>> v;
    v.push_back({MAX, -1});
    for (int i = 0; i < n; ++i) {
        while (v.back().first < a[i]) v.pop_back();
        lf[i] = v.back().second;
        v.push_back({a[i], i});
    }

    v.clear();
    v.push_back({MAX, n});
    for (int i = n-1; i >= 0; --i) {
        while (v.back().first < a[i]) v.pop_back();
        rg[i] = v.back().second;
        v.push_back({a[i], i});
    }

    for (int i = 0; i < n; ++i) {
        if (i-lf[i] < rg[i]-i) {
            calc(lf[i]+1, i, i+1, rg[i], a[i]);
        } else {
            calc(i+1, rg[i], lf[i]+1, i, a[i]);
        }
    }
    cout << an << endl;
    return 0;
}
