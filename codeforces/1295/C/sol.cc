#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int T;
    cin >> T;
    while (T--) {
        string s, t;
        cin >> s >> t;
        map<char, vector<int>> mp;
        for (int i = 0; i < (int) s.size(); ++i) {
            mp[s[i]].push_back(i);
        }
        int an = 0, idx = (int) s.size();
        for (int i = 0; i < (int) t.size(); ++i) {
            if (!mp.count(t[i])) {
                an = -1;
                break;
            }
            auto &v = mp[t[i]];
            auto it = lower_bound(v.begin(), v.end(), idx);
            if (it == v.end()) {
                ++an;
                idx = v[0] + 1;
            } else {
                idx = *it + 1;
            }
        }
        cout << an << '\n';
    }
    return 0;
}
