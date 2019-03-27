#include <bits/stdc++.h>

using namespace std;

const int MAX = (int) 1e5+11;
long long k, n, t, d, ans, D, type;
vector<pair<long long, long long>> v;
vector<long long> same;
bool used[MAX];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> k;
    for (int i = 0; i < n; ++i) {
        cin >> t >> d;
        v.push_back(make_pair(d, t));
    }
    sort(v.rbegin(), v.rend());
    for (int i = 0; i < k; ++i) {
        D += v[i].first;
        if (!used[v[i].second]) {
            used[v[i].second] = 1;
            ++type;
        } else {
            same.push_back(v[i].first);
        }
    }
    ans = D + type * type;
    for (int i = k; i < n && same.size(); ++i) {
        if (used[v[i].second]) continue;
        used[v[i].second] = 1;
        ++type;
        D -= same.back();
        same.pop_back();
        D += v[i].first;
        ans = max(ans, D + type * type);
    }
    cout << ans << endl;

    return 0;
}
