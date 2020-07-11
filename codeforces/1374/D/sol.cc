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
        map<int, int> cnt;
        for (int i = 0; i < n; ++i) {
            int v;
            cin >> v;
            v %= k;
            if (v != 0) {
                cnt[k-v]++;
            }
        }
        if (k == 1 || cnt.empty()) {
            cout << 0 << '\n';
        } else {
            int key = -1, val = -1;
            for (auto &kv: cnt) {
                if (kv.second >= val) {
                    key = kv.first, val = kv.second;
                }
            }
            cout << 1ll*(val-1)*k + key+1 << '\n';
        }
    }
    return 0;
}
