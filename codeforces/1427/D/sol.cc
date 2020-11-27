#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        --a[i];
    }
    vector<vector<int>> an;
    bool rev = false;
    while (true) {
        if (rev) reverse(a.begin(), a.end());
        int j = 0;
        vector<bool> b(n);
        vector<int> sz;
        vector<vector<int>> blks;
        for (int i = 0; i < n; ++i) if (b[i] == false) {
            vector<int> blk;
            while (a[j] != i) {
                blk.push_back(a[j]);
                b[a[j]] = true;
                ++j;
            }
            assert(a[j] == i);
            blk.push_back(a[j]);
            b[a[j]] = true;
            ++j;

            sz.push_back(blk.size());
            blks.push_back(blk);
        }
        if (!rev && blks.size() == n) {
            break;
        } else if (blks.size() > 1) {
            if (!rev) reverse(blks.begin(), blks.end());
            else reverse(sz.begin(), sz.end());
            an.push_back(sz);
            int i = 0;
            for (auto &blk: blks) {
                if (rev) reverse(blk.begin(), blk.end());
                for (auto x: blk) {
                    a[i++] = x;
                }
            }
        }
        rev = !rev;
    }

    cout << an.size() << '\n';
    for (auto &sz: an) {
        cout << sz.size() << ' ';
        for (auto x: sz) {
            cout << x << ' ';
        }
        cout << '\n';
    }
    return 0;
}
