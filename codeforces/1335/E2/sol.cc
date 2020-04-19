#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int tt;
    cin >> tt;
    while (tt--) {
        int n, an = 0;
        cin >> n;
        map<int, vector<int>> mp;
        for (int i = 0; i < n; ++i) {
            int x;
            cin >> x;
            mp[x].push_back(i);
        }

        for (auto &kv: mp) {
            an = max(an, (int)kv.second.size());
        }

        for (int v1 = 1; v1 <= 200; ++v1) if (mp.count(v1)) {
            for (int v2 = 1; v2 <= 200; ++v2) if (mp.count(v2)) {
                if (v1 == v2) continue;
                vector<int> &ve1 = mp[v1];
                vector<int> &ve2 = mp[v2];
                int i1 = 0, j1 = ve1.size()-1, i2 = 0, j2 = ve2.size()-1;
                int cnt = 1;
                while (i1 < j1) {
                    while (i2 <= j2 && ve2[i2] < ve1[i1]) ++i2;
                    while (i2 <= j2 && ve2[j2] > ve1[j1]) --j2;
                    an = max(an, 2*cnt + max(j2-i2+1, 0));
                    ++i1, --j1, ++cnt;
                }
            }
        }

        cout << an << '\n';
    }
    return 0;
}
