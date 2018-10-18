#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t, n, k;
    cin >> t;
    while (t--) {
        vector<int> a;
        cin >> n >> k;
        for (int i = 0; i < n; ++i) {
            int x;
            cin >> x;
            a.push_back(x);
        }
        sort(a.rbegin(), a.rend());
        k--;
        while (k+1 < n && a[k] == a[k+1]) ++k;
        cout << k+1 << '\n';
    }
    return 0;
}
