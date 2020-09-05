#include <bits/stdc++.h>

using namespace std;
using ll = long long;

ll calc(ll i, ll p, ll f, ll cnts, ll cntw, ll s, ll w)
{
    ll an = 0, v;

    v = min(i, p/s);
    an += v;
    cnts -= v;
    p -= v*s;

    v = min(cnts, f/s);
    an += v;
    cnts -= v;
    f -= v*s;

    v = min(cntw, p/w);
    an += v;
    cntw -= v;
    p -= v*w;

    v = min(cntw, f/w);
    an += v;
    cntw -= v;
    f -= v*w;
    return an;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--) {
        ll p, f, cnts, cntw, s, w;
        cin >> p >> f >> cnts >> cntw >> s >> w;
        if (s > w) {
            swap(s, w);
            swap(cnts, cntw);
        }

        ll an = 0;
        for (ll i = 0; i <= cnts; ++i) {
            an = max(an, calc(i, p, f, cnts, cntw, s, w));
        }
        cout << an << '\n';
    }
    return 0;
}
