#include <bits/stdc++.h>

using namespace std;
using ll = long long;

void update(vector<ll> &a, const vector<ll> &op)
{
    ll i = op[0], j = op[1], x = op[2];
    a[i] -= i*x;
    a[j] += i*x;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int tt;
    cin >> tt;
    while (tt--) {
        ll n;
        cin >> n;
        vector<ll> a(n+1);
        for (int i = 1; i <= n; ++i) {
            cin >> a[i];
        }
        ll sum = accumulate(a.begin(), a.end(), 0);
        if (sum % n) {
            cout << -1 << '\n';
            continue;
        }
        ll equal = sum/n;
        vector<vector<ll>> an;

        for (int i = 2; i <= n; ++i) {
            ll need = i-(a[i]%i);
            need %= i;
            if (need > 0) {
                an.push_back({1, i, need});
                update(a, an.back());
            }
            an.push_back({i, 1, a[i]/i});
            update(a, an.back());
        }

        for (int i = 2; i <= n; ++i) if (a[i] < equal) {
            an.push_back({1, i, equal-a[i]});
            update(a, an.back());
            assert(a[i] == equal);
        }
        assert(a[1] == equal);

        cout << an.size() << '\n';
        for (auto &op: an) {
            cout << op[0] << ' ' << op[1] << ' ' << op[2] << '\n';
        }
        // cerr << "dbg: "; for (int i = 1; i <= n; ++i) cerr << a[i] << ' '; cerr << endl;
    }
    return 0;
}
