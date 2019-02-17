#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for (auto &v: a) {
        cin >> v;
    }
    int mx = 0;
    for (int b = 0; b < n; ++b) {
        int now = 0;
        for (int i = 0; i < n; ++i) {
            if ((i-b) % k) {
                now += a[i];
            }
        }
        mx = max(mx, abs(now));
    }
    cout << mx << endl;
    return 0;
}
