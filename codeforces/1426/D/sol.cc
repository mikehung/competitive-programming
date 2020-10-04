#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    ll n;
    cin >> n;
    vector<ll> a(n);
    for (auto &it: a) cin >> it;
    map<ll, ll> mp;
    mp[0] = -1;
    vector<pair<ll, ll>> zero_segs;
    ll sum = 0, j = 1;
    for (int i = 0; i < n; ++i) {
        sum += a[i];
        if (mp.count(sum)) {
            zero_segs.push_back({mp[sum]+1, j});
            zero_segs.push_back({i, -j});
            ++j;
        }
        mp[sum] = i;
    }
    sort(zero_segs.begin(), zero_segs.end());

    ll an = 0;
    set<ll> opens;
    for (auto &seg: zero_segs) {
        // cout << seg.first << ' ' << seg.second << '\n';
        if (seg.second > 0) {
            opens.insert(seg.second);
        } else {
            if (opens.count(-seg.second)) {
                ++an;
                opens.clear();
            }
        }
    }
    cout << an << '\n';
    return 0;
}
