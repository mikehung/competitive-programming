#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
ll n, k;
vector<ll> v;

ll countless(ll X) {
    ll an = 0;

    for (auto &x: v) {
        if (x * x <= X) --an;
        if (x == 0) {
            if (X >= 0) an += n;
        } else if (x < 0) {
            ll y = X / x - 5;
            while (y * x > X) ++y;
            ll z = lower_bound(v.begin(), v.end(), y) - v.begin();
            an += n - z;
        } else if (x > 0) {
            ll y = X / x + 5;
            while (y * x > X) --y;
            ll z = upper_bound(v.begin(), v.end(), y) - v.begin();
            an += z;
        }
    }

    return an / 2;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> k;
    v.resize(n);
    for (auto &x: v) {
        cin >> x;
    }
    sort(v.begin(), v.end());

    ll INF = 1e18;
    ll lo = -INF-10, hi = INF+10, mid;
    while (lo < hi) {
        mid = lo + (hi-lo)/2;
        if (countless(mid) < k) {
            lo = mid+1;
        } else {
            hi = mid;
        }
    }
    cout << lo << endl;

    return 0;
}
