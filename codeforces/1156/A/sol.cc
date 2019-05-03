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
    int an = 0;
    for (int i = 1; i < n; ++i) {
        if (a[i-1] == 1) {
            an += a[i] == 2 ? 3 : 4;
        } else if (a[i-1] == 2) {
            if (a[i] == 1) an += 3;
            else {
                cout << "Infinite\n"; return 0;
            }
        } else {
            if (a[i] == 1) an += 4;
            else {
                cout << "Infinite\n"; return 0;
            }
        }
        if (i >= 2 && a[i] == 2 && a[i-1] == 1 && a[i-2] == 3) an--;
    }
    cout << "Finite\n" << an << endl;
    return 0;
}
