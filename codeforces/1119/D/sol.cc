#include <bits/stdc++.h>

using namespace std;

long long N, n, q, l, r;
vector<long long> a, b, c;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> N;
    a.resize(N);
    for (auto &v: a) cin >> v;
    sort(a.begin(), a.end());
    a.erase(unique(a.begin(), a.end()), a.end());
    sort(a.begin(), a.end());

    n = a.size();
    for (int i = 1; i < n; ++i) {
        b.push_back(a[i] - a[i-1]);
    }
    sort(b.begin(), b.end());
    c = b;
    for (int i = 1; i < c.size(); ++i) {
        c[i] += c[i-1];
    }

    cin >> q;
    while (q--) {
        cin >> l >> r;
        long long x = r - l + 1;
        int id = upper_bound(b.begin(), b.end(), x) - b.begin() - 1;
        cout << (id != -1 ? c[id] : 0) + x * (n - id - 1) << ' ';
    }
    cout << endl;
    return 0;
}
