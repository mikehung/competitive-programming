#include <bits/stdc++.h>

using namespace std;

int n, node, len, mxd, node2, len2, an1, an2;
map<int, vector<int>> g, dis;
vector<bool> visit;

void guess_all()
{
    cout << "? " << n;
    for (int i = 1; i <= n; ++i) {
        cout << ' ' << i;
    }
    cout << endl;
    cin >> node >> len;
}

void dfs(int u, int d)
{
    if (visit[u] || d > len) return;
    visit[u] = true;
    dis[d].push_back(u);
    mxd = max(mxd, d);
    for (auto v: g[u]) dfs(v, d+1);
}

bool check(int l)
{
    cout << "? " << dis[l].size();
    for (auto v: dis[l]) {
        cout << ' ' << v;
    }
    cout << endl;
    cin >> node2 >> len2;
    return len2 == len;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--) {
        cin >> n;
        g.clear();
        for (int i = 0; i < n-1; ++i) {
            int u, v;
            cin >> u >> v;
            g[u].push_back(v);
            g[v].push_back(u);
        }
        guess_all();

        mxd = 0;
        dis.clear();
        visit = vector<bool>(n+1);
        dfs(node, 0);
        int lo = (len+1)/2, hi = mxd, mid;
        while (lo <= hi) {
            mid = lo + (hi-lo)/2;
            if (check(mid)) {
                lo = mid+1;
                an1 = node2;
            } else {
                hi = mid-1;
            }
        }

        mxd = 0;
        dis.clear();
        visit = vector<bool>(n+1);
        dfs(an1, 0);
        check(len);
        an2 = node2;
        cout << "! " << an1 << ' ' << an2 << endl;

        string verdict;
        cin >> verdict;
        if (verdict == "Incorrect") {
            break;
        }
    }
    return 0;
}
