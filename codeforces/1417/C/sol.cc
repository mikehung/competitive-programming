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
        int n;
        cin >> n;
        map<int, vector<int>> mp;
        vector<int> an(n+1, -1);
        for (int i = 0; i < n; ++i) {
            int x;
            cin >> x;
            if (!mp.count(x)) mp[x].push_back(-1);
            mp[x].push_back(i);
        }

        int j = n;
        for (auto &[x, a]: mp) {
            a.push_back(n);
            int mx = 0;
            for (int i = 1; i < a.size(); ++i) {
                mx = max(mx, a[i]-a[i-1]);
            }
            while (j >= mx) {
                an[j] = x;
                --j;
            }
        }
        for (int i = 1; i <= n; ++i) {
            cout << an[i] << ' ';
        }
        cout << '\n';
    }
    return 0;
}
