#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, k;
    cin >> n >> k;
    if (k >= n) {
        cout << 0 << endl;
        return 0;
    }
    vector<int> h(n);
    for (auto &x: h) cin >> x;
    sort(h.begin(), h.end());
    long long all = 0;
    for (int i = 0; i < n-k; ++i) {
        all += h[i];
    }
    cout << all << endl;
    return 0;
}
