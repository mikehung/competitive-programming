#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int calc(const vector<int> &a, int l, int r)
{
    vector<int> v;
    for (int i = l+1; i < r; ++i) if (a[l] <= a[i] && a[i] <= a[r]) {
        auto it = upper_bound(v.begin(), v.end(), a[i]);
        if (it == v.end()) v.push_back(a[i]);
        else *it = a[i];
    }
    return r-l-1 - v.size();
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, k;
    cin >> n >> k;

    n += 2, k += 2;
    vector<int> a(n), b(k);
    a[0] = -1e9, a[n-1] = 2e9;
    b[0] = 0, b[k-1] = n-1;
    for (int i = 0; i < n-2; ++i) {
        cin >> a[i+1];
        a[i+1] -= i;
    }
    for (int i = 0; i < k-2; ++i) {
        cin >> b[i+1];
    }

    auto calc = [&](int l, int r, int lv, int rv) {
    };

    int an = 0;
    for (int i = 0; i < k-1; ++i) {
        if (a[b[i]] > a[b[i+1]]) {
            cout << -1 << '\n';
            return 0;
        }

        an += calc(a, b[i], b[i+1]);
    }
    cout << an << '\n';
    
    return 0;
}
