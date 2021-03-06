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
        int n;
        cin >> n;
        vector<ll> odd, even;
        for (int i = 1; i <= n; ++i) {
            if (i % 2) odd.push_back(i);
            else even.push_back(i);
        }

        vector<pair<ll, ll>> an;
        for (int i = 0; i < n-1; ++i) {
            pair<ll, ll> par;
            if (even.size() > 1) {
                par.first = even.back();
                even.pop_back();
                par.second = even.back();
                even.pop_back();
            } else if (odd.size() > 1) {
                par.first = odd.back();
                odd.pop_back();
                par.second = odd.back();
                odd.pop_back();
            } else {
                assert(odd.size() == 1 && even.size() == 1);
                par.first = odd.back();
                odd.pop_back();
                par.second = even.back();
                even.pop_back();
            }
            ll v = par.first + par.second;
            if (v % 2) v++;
            v /= 2;
            // cerr << "got: " << par.first <<  ' ' << par.second << ": push: " << v << endl;
            if (v % 2) odd.push_back(v);
            else even.push_back(v);
            an.push_back(par);
        }

        cout << (odd.empty() ? even[0] : odd[0]) << '\n';
        for (auto &par: an) {
            cout << par.first << ' ' << par.second << '\n';
        }
    }
    return 0;
}
