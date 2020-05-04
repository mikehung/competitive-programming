#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    ll n;
    cin >> n;
    vector<ll> a(n), pre(n+1);
    for (ll i = 0; i < n; ++i) {
        cin >> a[i];
        pre[i+1] = a[i] + pre[i];
    }

    map<ll, ll> mp;
    mp[0] = -1;
    ll an = 0, j = -1;
    for (int i = 0; i < n; ++i) {
        if (a[i] != 0) {
            if (mp.count(pre[i+1])) {
                j = max(j, mp[pre[i+1]]+1);
            }
            an += i - j;
        } else {
            mp[0] = i;
            j = max(j, mp[0]);
        }
        mp[pre[i+1]] = i;
    }
    cout << an << '\n';

    return 0;
}
