#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        vector<int> a(n);
        set<int> se;
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
            se.insert(a[i]);
        }
        if (se.size() > k) {
            cout << "-1\n";
            continue;
        }
        vector<int> b;
        for (auto &x: se) b.push_back(x);
        while (b.size() < k) b.push_back(b.back());

        cout << n * k << '\n';
        for (int i = 0; i < n; ++i) {
            for (auto &x: b) {
                cout << x << ' ';
            }
        }
        cout << '\n';
    }
    return 0;
}
