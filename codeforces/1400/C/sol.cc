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
        string s;
        cin >> s;
        int x;
        cin >> x;
        bool ok = true;
        int n = s.size();
        vector<int> an(n, 1);
        for (int i = 0; i < n; ++i) if (s[i] == '0') {
            if (i-x >= 0) an[i-x] = 0;
            if (i+x < n) an[i+x] = 0;
        }
        for (int i = 0; i < n; ++i) if (s[i] == '1') {
            bool check = false;
            if (i-x >= 0 && an[i-x] == 1) check = true;
            if (i+x < n && an[i+x] == 1) check = true;
            if (!check) ok = false;
        }
        if (ok) {
            for (auto x: an) cout << x;
            cout << '\n';
        } else {
            cout << -1 << '\n';
        }
    }
    return 0;
}
