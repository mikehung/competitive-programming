#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, k;
    cin >> n >> k;
    vector<int> p(n);
    for (auto &x: p) cin >> x;
    int mx = 0, cur = 0;
    for (int i = 0, j = 0; j < n; ++j) {
        cur += p[j];
        if (j-i+1 == k) {
            mx = max(mx, cur);
            cur -= p[i++];
        }
    }
    cout << fixed << setprecision(12) << (double) (mx+k) / 2.0 << endl;
    return 0;
}
