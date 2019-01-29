#include <bits/stdc++.h>

using namespace std;

const int MAX = 321;
int n, m, a[MAX], b[MAX], l[MAX], r[MAX];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> m;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        b[i] = a[i];
    }
    for (int i = 0; i < m; ++i) {
        cin >> l[i] >> r[i];
        --l[i], --r[i];
    }
    int mx = 0;
    vector<int> idx;
    for (int i = 0; i < n; ++i) {
        // restore a
        for (int j = 0; j < n; ++j) {
            a[j] = b[j];
        }
        // assume no segment overlap with i
        vector<int> cur;
        for (int j = 0; j < m; ++j) if (i < l[j] || i > r[j]) {
            cur.push_back(j);
            for (int k = l[j]; k <= r[j]; ++k) {
                --a[k];
            }
        }
        if (mx < a[i]-*min_element(a, a+n)) {
            mx = a[i]-*min_element(a, a+n);
            idx = cur;
        }
    }
    cout << mx << endl << idx.size() << endl;
    for (auto &x: idx) {
        cout << x+1 << ' ';
    }
    cout << endl;
    return 0;
}
