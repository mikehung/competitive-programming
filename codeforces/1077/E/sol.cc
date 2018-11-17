#include <bits/stdc++.h>

using namespace std;

int n, ans;
map<int, int> cnt;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n;
    for (int i = 0; i < n; ++i) {
        int x;
        cin >> x;
        ++cnt[x];
    }
    vector<int> vec;
    for (auto &kv: cnt) {
        vec.push_back(kv.second);
    }
    sort(vec.begin(), vec.end());
    for (int i = 1; i <= vec.back(); ++i) {
        int cur = 0, pos = 0, base = i;
        while (true) {
            auto it = lower_bound(vec.begin() + pos, vec.end(), base);
            if (it == vec.end()) break;
            cur += base;
            pos = it - vec.begin() + 1;
            base *= 2;
        }
        ans = max(ans, cur);
    }
    cout << ans << '\n';
    return 0;
}
