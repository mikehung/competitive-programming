#include <bits/stdc++.h>

using namespace std;

int n, k, s;
map<int, int> cnt, rep;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> k;
    for (int i = 0; i < n; ++i) {
        cin >> s;
        ++cnt[s];
    }
    priority_queue<pair<int, int>> pq;
    for (auto &kv: cnt) {
        pq.push(make_pair(kv.second, kv.first));
        rep[kv.first] = 1;
    }
    while (k--) {
        int x = pq.top().second;
        pq.pop();
        cout << x << ' ';
        rep[x]++;
        if (rep[x] <= cnt[x]) {
            pq.push(make_pair(cnt[x] / rep[x], x));
        }
    }
    cout << '\n';
    return 0;
}
