#include <bits/stdc++.h>

using namespace std;
using ll = long long;

const int N = 2e5+11;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    ll n, w;
    cin >> n >> w;
    vector<ll> a(N);
    for (int i = 0; i < n; ++i) {
        ll s, t, p;
        cin >> s >> t >> p;
        a[s] += p;
        a[t] -= p;
    }
    for (int i = 0; i < N; ++i) {
        if (i) a[i] += a[i-1];
        if (a[i] > w) {
            cout << "No\n";
            return 0;
        }
    }
    cout << "Yes\n";
    return 0;
}
