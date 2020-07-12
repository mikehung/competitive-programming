#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    ll n;
    cin >> n;
    vector<ll> a(n), b(n);;
    for (auto &it: b) cin >> it;
    int j = 0;
    for (int i = 0; i < n; i += 2, j++) a[j] = b[i];
    for (int i = 1; i < n; i += 2, j++) a[j] = b[i];
    ll an = 0, cur = 0, k = (n+1)/2;
    for (int i = 0; i < 2*n; ++i) {
        cur += a[i%n];
        if (i >= k) cur -= a[(i-k+n)%n];
        an = max(an, cur);
    }
    cout << an << '\n';
    return 0;
}
