#include <bits/stdc++.h>

using namespace std;

void solve()
{
    int n, st, en, idx;
    cin >> n;
    vector<tuple<int, int, int>> ve;
    for (int i = 0; i < n; ++i) {
        cin >> st >> en;
        ve.push_back(make_tuple(st, en, i));
    }
    sort(ve.begin(), ve.end());

    string an(n, '1');
    bool ok = true;
    int C = 0, J = 0;
    for (int i = 0; i < n; ++i) {
        tie(st, en, idx) = ve[i];
        if (st >= C) {
            an[idx] = 'C';
            C = en;
        } else if (st >= J) {
            an[idx] = 'J';
            J = en;
        } else {
            ok = false;
            break;
        }
    }
    cout << (ok ? an : "IMPOSSIBLE") << '\n';
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout << fixed << setprecision(6);
    int T;
    cin >> T;
    for (int t = 1; t <= T; ++t) {
        cout << "Case #" << t << ": ";
        solve();
    }
    return 0;
}
