#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        vector<long long> a(n), w(k);
        for (auto &it: a) cin >> it;
        for (auto &it: w) cin >> it;
        sort(a.begin(), a.end());
        sort(w.rbegin(), w.rend());
        long long an = 0;
        for (int i = 0; i < k; ++i) {
            an += a[n-i-1];
        }
        while (w.size() && w.back() == 1) {
            an += a.back();
            a.pop_back();
            w.pop_back();
        }
        int i = 0;
        for (auto wi: w) {
            an += a[i];
            i += wi-1;
        }
        cout << an << '\n';
    }
    return 0;
}
