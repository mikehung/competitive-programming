#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int tt;
    cin >> tt;
    while (tt--) {
        int n, x;
        cin >> n >> x;
        vector<int> cnt(2);
        for (int i = 0; i < n; ++i) {
            int v;
            cin >> v;
            cnt[v%2]++;
        }
        if (cnt[1] == 0) {
            cout << "No\n";
        } else {
            int u = min(cnt[1], x);
            if (u % 2 == 0) --u;
            x -= u;
            cout << ((cnt[0] >= x) ? "Yes" : "No") << '\n';
        }
    }
    return 0;
}
