#include <bits/stdc++.h>

using namespace std;

vector<int> b(200011);

bool check1(const vector<int> &a, int lo, int hi)
{
    if (lo >= hi) return false;
    int n = hi-lo;
    for (int i = 1; i <= n; ++i) {
        b[i] = 0;
    }
    for (int i = lo; i < hi; ++i) {
        if (a[i] < 1 || a[i] > n) return false;
        b[a[i]] = 1;
    }
    for (int i = 1; i <= n; ++i) {
        if (!b[i]) return false;
    }
    return true;
}

bool check(const vector<int> &a, int n)
{
    return check1(a, 0, n) && check1(a, n, a.size());
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--) {
        int n, mx = 0;
        cin >> n;
        vector<int> a(n);
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
            mx = max(mx, a[i]);
        }
        if (mx > n) {
            cout << 0 << '\n';
            continue;
        }

        vector<int> an;
        if (check(a, mx)) {
            an.push_back(mx);
        }
        if (n-mx != mx && check(a, n-mx)) {
            an.push_back(n-mx);
        }
        cout << an.size() << '\n';
        for (auto x: an) {
            cout << x << ' ' << n-x << '\n';
        }
    }
    return 0;
}
