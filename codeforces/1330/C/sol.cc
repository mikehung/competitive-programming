#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, m;
    cin >> n >> m;
    vector<int> a(m);
    for (int i = 0; i < m; ++i) {
        cin >> a[i];
        if (a[i] >= n-i+1) {
            cout << -1 << '\n';
            return 0;
        }
    }
    vector<long long> suff(m+1);
    for (int i = m-1; i >= 0; --i) {
        suff[i] = suff[i+1] + a[i];
    }
    if (suff[0] < n) {
        cout << -1 << '\n';
        return 0;
    }

    for (int i = 0; i < m; ++i) {
        cout << max((long long)i+1, n-suff[i]+1) << ' ';
    }
    cout << '\n';

    return 0;
}
