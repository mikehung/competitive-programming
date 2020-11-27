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
        ll n;
        cin >> n;
        map<ll, ll> f;
        for (ll i = 2; i*i <= n; i++) {
            while (n % i == 0) {
                n /= i;
                f[i]++;
            }
        }
        if (n > 1) f[n]++;
        vector<ll> an;
        for (auto kv: f) {
            for (int i = 0; i < kv.second; ++i) {
                if (an.size() == i) an.push_back(1);
                an[i] *= kv.first;
            }
        }
        reverse(an.begin(), an.end());
        cout << an.size() << '\n';
        for (auto &x: an) cout << x << ' ';
        cout << '\n';
    }
    return 0;
}
