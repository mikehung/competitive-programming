#include <bits/stdc++.h>

using namespace std;
using ll = long long;

ll calc(const vector<int> &b) {
    int n = b.size();
    if (n <= 1) return 0;
    vector<int> left(n), right(n), a(n);
    for (int i = 0; i < n; ++i) {
        left[i] = i-1;
        right[i] = i+1;
        a[i] = i;
    }
    sort(a.begin(), a.end(), [&](int i, int j) {
        return b[i] < b[j];
    });
    ll an = 0;
    for (int i = 0; i < n-1; ++i) {
        int op = INT_MAX, j = a[i];
        if (left[j] >= 0 && left[j] < n) op = min(op, b[left[j]]-b[j]);
        if (right[j] >= 0 && right[j] < n) op = min(op, b[right[j]]-b[j]);
        an += op;
        if (left[j] >= 0 && left[j] < n) right[left[j]] = right[j];
        if (right[j] >= 0 && right[j] < n) left[right[j]] = left[j];
    }
    return an;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> a(n);
        for (auto &it: a) cin >> it;
        ll an = 0;
        int mx = -1;
        vector<int> b;
        for (int i = 0; i < n; ++i) {
            if (mx == -1 || a[i] < mx) {
                b.push_back(a[i]);
                mx = max(mx, a[i]);
            } else {
                an += calc(b);
                b = {a[i]};
                mx = a[i];
            }
        }
        an += calc(b);
        cout << an << '\n';
    }
    return 0;
}
