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
        for (auto &it: a) cin >> it;
        bool ok = false;
        for (int i = 0; i < n && !ok; ++i) if (i == 0 || a[i] < a[i-1]) {
            for (int j = i+1; j < n && !ok; ++j) if (a[i] < a[j]) {
                for (int k = j+1; k < n && !ok; ++k) if (a[j] > a[k]) {
                    cout << "YES\n" << i+1 << ' ' << j+1 << ' ' << k+1 << '\n';
                    ok = true;
                }
            }
        }
        if (!ok) {
            cout << "NO\n";
        }
    }
    return 0;
}
