#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int tt;
    cin >> tt;
    while (tt--) {
        int n;
        cin >> n;
        vector<int> a;
        map<int, int> mp;
        for (int i = 0; i < n; ++i) {
            int x;
            cin >> x;
            a.push_back(x);
            mp[x] = i;
        }

        int i = 1, j = n, ok = 1;
        while (i <= n && ok) {
            int end = j;
            j = mp[i];
            for (int k = mp[i]; k < end; ++k, ++i) {
                if (a[k] != i) {
                    ok = 0;
                    break;
                }
            }
        }
        cout << (ok ? "Yes" : "No") << '\n';
    }
    return 0;
}
