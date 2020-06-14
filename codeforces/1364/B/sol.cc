#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> a(n);
        for (auto &it: a) cin >> it;
        vector<int> an = {a[0], a[1]};
        for (int i = 2; i < n; ++i) {
            int sz = an.size();
            if (an[sz-2] > an[sz-1] && an[sz-1] > a[i]) {
                an[sz-1] = a[i];
            } else if (an[sz-2] < an[sz-1] && an[sz-1] < a[i]) {
                an[sz-1] = a[i];
            } else {
                an.push_back(a[i]);
            }
        }
        cout << an.size() << '\n';
        for (auto x: an) cout << x << ' '; cout << '\n';
    }
    return 0;
}
