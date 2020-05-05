#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--) {
        int n, x;
        cin >> n >> x;
        vector<int> a(500);
        for (int i = 0; i < n; ++i) {
            int v;
            cin >> v;
            a[v] = 1;
        }

        for (int i = 1; i < 500 && x; ++i) {
            if (a[i] == 0) --x, a[i] = 1;
        }

        for (int i = 1; i < 500; ++i) {
            if (a[i] == 0) {
                cout << i-1 << '\n';
                break;
            }
        }
    }
    return 0;
}
