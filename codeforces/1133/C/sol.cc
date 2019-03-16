#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    vector<int> a(n);
    for (auto &x: a) cin >> x;
    sort(a.begin(), a.end());
    int res = 0, j = 0;
    for (int i = 0; i < n; ++i) {
        while (a[i] - a[j] > 5) j++;
        res = max(res, i - j + 1);
    }
    cout << res << endl;
    return 0;
}
