#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int n, sqrtn, mex = 1;
vector<int> a, freq, mexes;
vector<vector<int>> indices;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> n;

    sqrtn = sqrt(n);
    a.resize(n);
    indices.resize(n+1);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        indices[a[i]].push_back(i);
    }

    vector<pair<int, int>> segs;
    for (int i = 1; i <= n; ++i) if (indices[i].size()) {
        int l = 0;
        for (int r: indices[i]) {
            segs.push_back({l, r-1});
            l = r+1;
        }
        segs.push_back({l, n-1});
    }
    segs.push_back({0, n-1});

    sort(segs.begin(), segs.end(), [&](pair<int, int> &p1, pair<int, int> &p2){
        return make_pair(p1.first/sqrtn, p1.second) < make_pair(p2.first/sqrtn, p2.second);
    });

    auto update = [&](int idx, int val){
        freq[idx] += val;
        if (freq[idx] == 0) mex = min(mex, idx);
        while (freq[mex] > 0) mex++;
    };

    freq.resize(n+11);
    int l = 0, r = -1;
    for (auto &seg: segs) {
        int lx = seg.first, rx = seg.second;
        if (lx > rx) continue;
        while (l < lx) update(a[l++], -1);
        while (rx < r) update(a[r--], -1);
        while (lx < l) update(a[--l], 1);
        while (rx > r) update(a[++r], 1);
        mexes.push_back(mex);
    }
    sort(mexes.begin(), mexes.end());
    mexes.erase(unique(mexes.begin(), mexes.end()), mexes.end());
    int an = mexes.size()+1;
    for (int i = 0; i < mexes.size(); ++i) {
        if (mexes[i] != i+1) {
            an = i+1;
            break;
        }
    }
    cout << an << '\n';
    return 0;
}
