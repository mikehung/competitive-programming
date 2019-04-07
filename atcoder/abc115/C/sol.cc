#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for (auto &v: a) cin >> v;
    sort(a.begin(), a.end());
    int ans = INT_MAX;
    for (int i = 0, j = k-1; j < n; ++i, ++j) {
        ans = min(ans, a[j] - a[i]);
    }
    cout << ans << endl;
    return 0;
}
