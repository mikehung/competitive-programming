#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, m;
    cin >> n >> m;
    vector<int> a(m);
    long long sum = 0;
    for (int i = 0; i < m; ++i) {
        cin >> a[i];
        sum += a[i];
    }
    if (sum < n) {
        cout << -1 << '\n';
        return 0;
    }

    int pos = 1;
    long long left = sum - n;
    vector<int> an(m);
    for (int i = 0; i < m; ++i) {
        // cerr << "xx: " << i << ' ' << pos << ' ' << left << ' ' << a[i]-1 << endl;
        an[i] = pos;
        if (pos+a[i]-1 > n) {
            cout << -1 << '\n';
            return 0;
        }
        long long sz = min(left, 1ll*a[i]-1);
        left -= sz;
        pos += a[i]-sz;
    }

    for (auto x: an) {
        cout << x << ' ';
    }
    cout << '\n';
    return 0;
}
