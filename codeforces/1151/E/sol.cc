#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    vector<int> a(n);
    for (auto &v: a) cin >> v;
    long long an = 0, x, y;
    for (int i = 0; i < n; ++i) {
        if (i == 0 || a[i-1] > a[i]) {
            x = a[i], y = i == 0 ? n+1 : a[i-1];
            an += x * (y - x);
        } else {
            x = a[i-1], y = a[i];
            an += (y-x) * (n+1-y);
        }
    }
    cout << an << endl;
    return 0;
}
