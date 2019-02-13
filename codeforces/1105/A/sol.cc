#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    vector<int> a(n);
    for (auto &x: a) {
        cin >> x;
    }
    int best_t = 1, mn = INT_MAX;
    for (int t = 1; t < 105; ++t) {
        int cur = 0;
        for (auto x: a) {
            int tt = abs(x - t);
            for (int j = -1; j <= 1; ++j) {
                if (abs(x - t+j) < tt) {
                    tt = abs(x - t+j);
                }
            }
            cur += tt;
        }
        if (cur < mn) {
            mn = cur;
            best_t = t;
        }
    }
    cout << best_t << ' ' << mn << '\n';
    return 0;
}
