#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    const int M = 1e9+7;
    int n, x, pos;
    cin >> n >> x >> pos;

    vector<int> a(n);
    a[pos] = 1;
    int l = 0, r = n;
    while (l < r) {
        int m = (l+r)/2;
        if (m <= pos) {
            a[m] = 1;
            l = m+1;
        } else {
            a[m] = 2;
            r = m;
        }
    }

    int cnt1 = count(a.begin(), a.end(), 1);
    int cnt2 = count(a.begin(), a.end(), 2);
    if (cnt1 > x || cnt2 > n-x) {
        cout << 0 << '\n';
        return 0;
    }

    ll an = 1;
    for (int i = 1; i < cnt1; ++i) {
        an *= x-i;
        an %= M;
    }
    for (int i = 0; i < cnt2; ++i) {
        an *= n-x-i;
        an %= M;
    }
    for (int i = 1; i <= n-cnt1-cnt2; ++i) {
        an *= i;
        an %= M;
    }
    cout << an << '\n';
    return 0;
}
