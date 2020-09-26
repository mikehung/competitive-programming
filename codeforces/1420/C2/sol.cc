#include <bits/stdc++.h>

using namespace std;
using ll = long long;

ll an = 0;

ll calc(const vector<ll> &a, int i)
{
    if (i < 0 || i+1 >= a.size()) return 0;
    return max(0ll, a[i]-a[i+1]);
}

void update(vector<ll> &a, int i, int v)
{
    an -= calc(a, i);
    an -= calc(a, i-1);
    a[i] = v;
    an += calc(a, i);
    an += calc(a, i-1);
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--) {
        int n, q;
        cin >> n >> q;
        vector<ll> a(n);
        for (auto &it: a) cin >> it;
        a.push_back(0);

        an = 0;
        for (int i = 0; i < a.size(); ++i) {
            an += calc(a, i);
        }
        cout << an << '\n';
        while (q--) {
            int l, r;
            cin >> l >> r;
            --l, --r;
            int al = a[l];
            update(a, l, a[r]);
            update(a, r, al);
            cout << an << '\n';
        }
    }
    return 0;
}
