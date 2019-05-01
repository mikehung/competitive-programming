#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, k;
    cin >> n >> k;
    vector<pair<int, int>> a;
    vector<int> an(n), pre(n), nxt(n);
    for (int i = 0; i < n; ++i) {
        int x;
        cin >> x;
        a.push_back(make_pair(x, i));
        pre[i] = i - 1;
        nxt[i] = i + 1;
    }
    sort(a.rbegin(), a.rend());
    int team = 1, cnt;
    for (int i = 0; i < n; ++i) {
        int idx = a[i].second;
        if (an[idx]) continue;
        an[idx] = team;

        int forward = nxt[idx];
        cnt = 0;
        while (forward >= 0 && forward < n) {
            if (an[forward] == 0) {
                an[forward] = team;
                if (++cnt == k) break;
            }
            forward = nxt[forward];
        }
        int bakward = pre[idx];
        cnt = 0;
        while (bakward >= 0 && bakward < n) {
            if (an[bakward] == 0) {
                an[bakward] = team;
                if (++cnt == k) break;
            }
            bakward = pre[bakward];
        }
        if (forward >= 0 && forward < n) pre[forward] = bakward;
        if (bakward >= 0 && bakward < n) nxt[bakward] = forward;

        team = team == 1 ? 2 : 1;
    }
    for (auto &v: an) cout << v; cout << endl;
    return 0;
}
