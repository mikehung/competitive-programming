#include <bits/stdc++.h>

using namespace std;
using ll = long long;

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
        bool same = true;
        for (int i = 1; i < n; ++i) {
            if (a[0] != a[i]) same = false;
        }
        cout << (same ? n : 1) << '\n';
    }
    return 0;
}
