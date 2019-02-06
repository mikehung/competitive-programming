#include <bits/stdc++.h>

using namespace std;

long long n, k, m;
vector<int> a;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> k >> m;
    for (int i = 0; i < n; ++i) {
        int x;
        cin >> x;
        a.push_back(x);
    }
    sort(a.rbegin(), a.rend());
    long double ans = 0, sum = 0;
    int del = min(m, n-1);
    m -= del;
    for (int i = 0; i < n - del; ++i) sum += a[i];
    for (int i = n - del; i <= n; ++i, ++m) {
        ans = max(ans, (sum + min(m, i*k)) / i);
        sum += a[i];
    }
    cout << fixed << setprecision(20) << ans << endl;
    return 0;
}
