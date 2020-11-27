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
        vector<int> a(n);
        map<int, vector<int>> mp;
        for (int i = 0; i < n; ++i) {
            int x;
            cin >> x;
            a[i] = x;
            if (mp[x].size() && mp[x].back() == i-1) {
                mp[x].back() = i;
            } else {
                mp[x].push_back(i);
            }
        }

        int an = 1e9;
        for (auto &kv: mp) {
            int cur = kv.second.size()+1;
            if (kv.first == a[0]) cur--;
            if (kv.first == a[n-1]) cur--;
            an = min(an, cur);
        }
        cout << an << '\n';
    }
    return 0;
}
