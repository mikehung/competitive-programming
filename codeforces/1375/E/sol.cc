#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    vector<int> a(n), b(n);
    for (auto &it: a) cin >> it;
    iota(b.begin(), b.end(), 0);
    sort(b.begin(), b.end(), [&](int i, int j) {
        if (a[i] != a[j]) {
            return a[i] < a[j];
        }
        return i < j;
    });

    vector<pair<int, int>> an;
    for (int round = 0; round < n; ++round) {
        for (int i = 0; i < n-1; ++i) {
            if (b[i] > b[i+1]) {
                an.push_back({b[i], b[i+1]});
                swap(b[i], b[i+1]);
            }
        }
    }
    cout << an.size() << '\n';
    if (an.size()) {
        for (auto &par: an) {
            cout << par.second+1 << ' ' << par.first+1 << '\n';
        }
    }

    return 0;
}
