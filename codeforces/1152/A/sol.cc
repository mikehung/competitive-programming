#include <bits/stdc++.h>

using namespace std;
int n, m, a0, a1, b0, b1;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> m;
    vector<int> a(n), b(m);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        if (a[i] & 1) a1++;
        else a0++;
    }
    for (int i = 0; i < m; ++i) {
        cin >> b[i];
        if (b[i] & 1) b1++;
        else b0++;
    }
    cout << min(a0, b1) + min(a1, b0) << endl;
    return 0;
}
