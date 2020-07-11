#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, k;
    cin >> n >> k;
    vector<int> vall, va, vb;
    for (int i = 0; i < n; ++i) {
        int t, a, b;
        cin >> t >> a >> b;
        if (a == 1 && b == 1) {
            vall.push_back(t);
        } else if (a == 1 && b == 0) {
            va.push_back(t);
        } else if (a == 0 && b == 1) {
            vb.push_back(t);
        }
    }
    if ((vall.size() + va.size() < k) || (vall.size() + vb.size()) < k) {
        cout << -1 << '\n';
        return 0;
    }

    sort(vall.rbegin(), vall.rend());
    sort(va.rbegin(), va.rend());
    sort(vb.rbegin(), vb.rend());
    int an = 0;
    while (k--) {
        if (vall.empty()) {
            an += va.back() + vb.back();
            va.pop_back();
            vb.pop_back();
        } else if (va.empty() || vb.empty()) {
            an += vall.back();
            vall.pop_back();
        } else {
            if (vall.back() < va.back() + vb.back()) {
                an += vall.back();
                vall.pop_back();
            } else {
                an += va.back() + vb.back();
                va.pop_back();
                vb.pop_back();
            }
        }
    }
    cout << an << '\n';

    return 0;
}
