#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int x;
    cin >> x;
    vector<int> v;
    while (x) {
        v.push_back(x & 1);
        x /= 2;
    }
    reverse(v.begin(), v.end());
    int an = 0, n = v.size();
    vector<int> op;
    for (int i = 0; i < n; ++i) if (v[i] == 0) {
        ++an;
        op.push_back(n - i);
        bool ok = true;
        for (int j = i; j < n; ++j) {
            v[j] = 1 - v[j];
            if (v[j] == 0) ok = false;
        }
        if (ok) break;
        ++an;
        for (int j = n-1; j >= 0; --j) {
            v[j] = 1 - v[j];
            if (v[j] == 1) break;
        }
    }
    cout << an << endl;
    if (an) {
        for (auto x: op) cout << x << ' '; cout << endl;
    }
    return 0;
}
