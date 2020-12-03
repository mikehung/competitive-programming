#include <bits/stdc++.h>

using namespace std;
using ll = long long;

const bool MULTI_TESTCASES = 1;

void solve()
{
    int n;
    cin >> n;
    vector<ll> a;
    a.push_back(0);
    for (ll i = 1; i < 3000; ++i) {
        a.push_back(i+a.back());
        if (a.back() > 2e6) break;
    }
    for (ll i = 1; i < 3000; ++i) {
        if (n > a[i]) continue;
        if (n == a[i]-1) {
            cout << i+1 << '\n';
        } else {
            cout << i << '\n';
        }
        return;
    }
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
