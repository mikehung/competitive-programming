#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, m;
    cin >> n >> m;
    vector<int> a(n), b(m);
    for (auto &it: a) cin >> it;
    for (auto &it: b) cin >> it;

    vector<vector<int>> cand(n);
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cand[i].push_back(j);
        }
    }
    int an = 0;
    for (int x = 11; x >= 0; --x) {
        vector<vector<int>> ncand(n);
        bool ok = true;
        for (int i = 0; i < n; ++i) {
            if ((a[i]>>x) & 1) {
                for (auto j: cand[i]) {
                    if (((b[j]>>x) & 1) == 0) {
                        ncand[i].push_back(j);
                    }
                }
                if (ncand[i].empty()) {
                    ok = false;
                    break;
                }
            } else {
                ncand[i] = cand[i];
            }
        }
        if (ok) {
            swap(cand, ncand);
        } else {
            an |= (1 << x);
        }
        /*
        cerr << "x: " << x << "\n";
        for (int i = 0; i < n; ++i) {
            cerr << "cand: " << i << '\n';
            for (auto j: cand[i]) {
                cerr << j << ' ';
            }
            cerr << endl;
        }
        */
    }
    cout << an << '\n';
    return 0;
}
