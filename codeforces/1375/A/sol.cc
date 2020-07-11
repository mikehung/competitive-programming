#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> a(n);
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
            if (i % 2) {
                if (a[i] > 0) a[i] = -a[i];
            } else {
                if (a[i] < 0) a[i] = -a[i];
            }
            cout << a[i] << ' ';
        }
        cout << '\n';
    }
    return 0;
}
