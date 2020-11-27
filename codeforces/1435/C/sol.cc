#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    const int N = 6;
    vector<int> a(N);
    for (auto &it: a) cin >> it;

    int n;
    cin >> n;
    vector<pair<int, int>> v;
    for (int i = 0; i < n; ++i) {
        int y;
        cin >> y;
        for (int x: a) {
            v.push_back({y-x, i});
        }
    }
    sort(v.begin(), v.end());
    int an = INT_MAX, missing = n, i = 0, j = -1, sz = v.size();
    vector<int> freq(n);
    while (true) {
        if (missing == 0) {
            an = min(an, v[j].first - v[i].first);
            if (freq[v[i++].second]-- == 1) {
                missing++;
            }
        } else {
            if (j == sz-1) break;
            if (freq[v[++j].second]++ == 0) {
                missing--;
            }
        }
    }
    cout << an << '\n';
    return 0;
}
