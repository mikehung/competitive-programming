#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int tt;
    cin >> tt;
    while (tt--) {
        int n, x, y;
        cin >> n >> x >> y;
        vector<int> a(n), an(n);
        vector<vector<int>> idx(n+2);
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
            idx[a[i]].push_back(i);
        }

        priority_queue<pair<int, int>> pq;
        for (int i = 1; i <= n+1; ++i) if (idx[i].size()) {
            pq.push({idx[i].size(), i});
        }

        int missing;
        for (int i = 1; i <= n+1; ++i) if (idx[i].empty()) {
            missing = i;
            break;
        }

        for (int i = 0; i < x; ++i) {
            auto par = pq.top();
            pq.pop();
            par.first--;
            if (par.first > 0) {
                pq.push(par);
            }
            an[idx[par.second].back()] = par.second;
            idx[par.second].pop_back();
        }

        int mx = 1;
        for (int i = 1; i <= n+1; ++i) {
            if (idx[mx].size() < idx[i].size()) mx = i;
        }

        int offer;
        if (idx[mx].size() <= n-x-idx[mx].size()) {
            offer = n-x;
        } else {
            offer = 2 * (n-x-idx[mx].size());
        }
        vector<int> idx1, idx2;
        for (int i = 1; i <= n+1; ++i) {
            for (auto x: idx[i]) idx1.push_back(x);
        }

        if (offer < y-x) {
            cout << "NO\n";
        } else {
            cout << "YES\n";
            int sz = idx1.size();
            for (int i = 0; i < sz; ++i) {
                idx2.push_back(idx1[(i+sz/2)%sz]);
            }
            int cnt = n-y;
            for (int i = 0; i < sz && cnt > 0; ++i) if (a[idx1[i]] == a[idx2[i]]) {
                idx2[i] = -1;
                --cnt;
            }
            for (int i = 0; i < sz && cnt > 0; ++i) if (idx2[i] != -1) {
                idx2[i] = -1;
                --cnt;
            }
            for (int i = 0; i < sz; ++i) {
                an[idx1[i]] = idx2[i] == -1 ? missing : a[idx2[i]];
            }
            for (auto x: an) cout << x << ' '; cout << endl;


        }
    }
    return 0;
}
