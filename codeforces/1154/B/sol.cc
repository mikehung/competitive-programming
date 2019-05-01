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
    sort(a.begin(), a.end());
    a.erase(unique(a.begin(), a.end()), a.end());
    if (a.size() == 1) {
        cout << 0 << endl;
    } else if (a.size() == 2) {
        if ((a[1] - a[0]) & 1) {
            cout << a[1] - a[0] << endl;
        } else {
            cout << (a[1] - a[0]) / 2 << endl;
        }
    } else if (a.size() == 3) {
        if (a[1] - a[0] == a[2] - a[1]) {
            cout << a[1] - a[0] << endl;
        } else {
            cout << -1 << endl;
        }
    } else {
        cout << -1 << endl;
    }
    return 0;
}
