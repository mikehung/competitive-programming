#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        vector<int> a(n), b(n);
        for (auto &it: a) cin >> it;
        for (auto &it: b) cin >> it;
        sort(a.begin(), a.end());

        if (a[n-1]-a[0] <= 2*k) {
            cout << n << '\n';
            continue;
        }

        set<pair<int, int>> se, nse;
        multiset<int> cnts;
        for (int i = 0, j = 0; i < n; ++i) {
            while (j < n && a[i]+k >= a[j]) ++j;
            se.insert({i, j});
            cnts.insert(j-i);
        }
        nse = se;

        int an = 0;
        for (auto &[i, j] : nse) {
            int cur = j-i;
            while (se.size() && j > se.begin()->first) {
                int x = se.begin()->second - se.begin()->first;
                cnts.erase(cnts.find(x));
                se.erase(se.begin());
            }
            assert(cnts.size() == se.size());

            if (cnts.size()) cur += *cnts.rbegin();
            an = max(an, cur);
        }

        cout << an << '\n';
    }
    return 0;
}
