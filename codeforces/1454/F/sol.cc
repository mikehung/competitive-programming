#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int tt;
    cin >> tt;
    while (tt--) {
        int n;
        cin >> n;
        vector<int> a(n);
        for (auto &it: a) cin >> it;
        multiset<int> first, second, third;
        first.insert(a[0]);
        for (int i = 1; i < n-1; ++i) {
            second.insert(a[i]);
        }
        third.insert(a[n-1]);
        vector<int> an;
        int l = 0, r = n-1;
        while (l < r) {
            int v = *first.rbegin();
            while (l+1 < r && a[r-1] <= v) {
                second.erase(second.find(a[r-1]));
                third.insert(a[r-1]);
                --r;
            }
            if (*third.rbegin() == v) {
                if (second.empty() || *second.begin() > v) {
                    if (third.size() > 1) {
                        second.insert(a[r]);
                        third.erase(third.find(a[r]));
                        ++r;
                    }
                }
                if (*second.begin() == v && *third.rbegin() == v) {
                    an = {l, r};
                    break;
                }
            }
            first.insert(a[l+1]);
            if (second.size()) second.erase(second.find(a[l+1]));
            ++l;
        }
        if (an.empty()) {
            cout << "NO\n";
        } else {
            cout << "YES\n" << an[0]+1 << ' ' << an[1]-an[0]-1 << ' ' << n-an[1] << '\n';
        }
    }
    return 0;
}
