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
        map<int, int> cnt;
        for (int i = 0; i < n; ++i) {
            int x;
            cin >> x;
            cnt[x]++;
        }
        int mx = 0, sz = cnt.size();
        for (auto &kv: cnt) mx = max(mx, kv.second);
        cout << (mx == sz ? mx-1 : min(mx, sz)) << '\n';
    }
    return 0;
}
