#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        vector<int> a(n), b(n);
        for (int &it: a) cin >> it;
        for (int &it: b) cin >> it;
        sort(a.begin(), a.end());
        sort(b.rbegin(), b.rend());
        for (int i = 0; i < k; ++i) {
            if (a[i] < b[i]) {
                swap(a[i], b[i]);
            }
        }
        int an = 0;
        for (int i = 0; i < n; ++i) an += a[i];
        cout << an << '\n';
    }
    return 0;
}
