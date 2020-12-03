#include <bits/stdc++.h>

using namespace std;
using ll = long long;

const bool MULTI_TESTCASES = 1;

void solve()
{
    const ll INF = 2e9+11;
    const int N = 4;
    array<ll, 4> X, Y;

    for (int i = 0; i < N; ++i) {
        cin >> X[i] >> Y[i];
    }

    array<int, 4> idx = {0, 1, 2, 3};
    auto calc = [&](ll k) {
        array<ll, 4> xs = {{X[idx[0]], X[idx[1]]-k, X[idx[2]], X[idx[3]]-k}};
        array<ll, 4> ys = {{Y[idx[0]], Y[idx[1]], Y[idx[2]]-k, Y[idx[3]]-k}};
        sort(xs.begin(), xs.end());
        sort(ys.begin(), ys.end());

        ll an = 0;
        for (int i = 0; i < N; ++i) {
            an += abs(xs[i]-xs[2]) + abs(ys[i]-ys[2]);
        }
        return an;
    };

    ll an = INF;
    do {
        ll l = 0, r = INF;
        while (r-l >= 2) {
            ll m = l + (r-l)/2;
            ll c1 = calc(m);
            ll c2 = calc(m+1);
            if (c1 > c2) {
                l = m+1;
            } else {
                r = m;
            }
        }

        for (ll i = l; i <= r; ++i) {
            an = min(an, calc(i));
        }
    } while (next_permutation(idx.begin(), idx.end()));

    cout << an << '\n';
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int testcases = 1;
    if (MULTI_TESTCASES) cin >> testcases;
    while (testcases--) solve();
    return 0;
}
