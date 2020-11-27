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
        for (int i = 0; i < n; ++i) {
            int x;
            cin >> x;
            mp[x].push_back(i+1);
        }
        int an = -1;
        for (auto &kv: mp) if (kv.second.size() == 1) {
            an = kv.second[0];
            break;
        }
        cout << an << '\n';
    }
    return 0;
}
