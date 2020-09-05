#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    ll n, d, m;
    cin >> n >> d >> m;
    vector<ll> le, gt;
    for (int i = 0; i < n; ++i) {
        ll x;
        cin >> x;
        if (x > m) {
            gt.push_back(x);
        } else {
            le.push_back(x);
        }
    }
    sort(le.begin(), le.end());
    sort(gt.rbegin(), gt.rend());

    vector<ll> pre_le(le.size()+1);
    vector<ll> pre_gt(gt.size()+1);
    for (int i = 0; i < le.size(); ++i) {
        pre_le[i+1] = pre_le[i] + le[i];
    }
    for (int i = 0; i < gt.size(); ++i) {
        pre_gt[i+1] = pre_gt[i] + gt[i];
    }

    ll an = pre_le[le.size()];
    for (int i = 1; i <= gt.size() && i+(i-1)*d <= n; ++i) {
        int idx = (i-1)*d - (gt.size()-i);
        if (idx < 0) idx = 0;
        an = max(an, pre_gt[i] + pre_le[le.size()] - pre_le[idx]);
    }
    cout << an << '\n';
    return 0;
}
