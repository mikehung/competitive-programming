#include <bits/stdc++.h>

using namespace std;

long long n, m, k, res, mx1, mx2;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> m >> k;
    vector<long long> a(n);
    for (auto &v: a) {
        cin >> v;
    }
    sort(a.begin(), a.end());
    mx1 = a[n-1];
    mx2 = a[n-2];
    cout << 1ll * (m/(k+1)) * (k*mx1+mx2) + (m%(k+1))*mx1 << '\n';

    return 0;
}
