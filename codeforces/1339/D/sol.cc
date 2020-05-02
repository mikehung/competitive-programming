#include <bits/stdc++.h>

using namespace std;

vector<int> deg(1e5+11), pdeg(1e5+11);
map<int, vector<int>> g;
vector<int> lens;

void dfs(int root, int parent, int len)
{
    if (parent != -1 && deg[root] == 1) {
        lens.push_back(len);
        return;
    }

    for (auto &child: g[root]) {
        if (child != parent) {
            dfs(child, root, len+1);
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    for (int i = 0; i < n-1; ++i) {
        int a, b;
        cin >> a >> b;
        --a, --b;
        g[a].push_back(b);
        g[b].push_back(a);
        deg[a]++;
        deg[b]++;
    }
    int root = -1;
    for (int i = 0; i < n; ++i) if (deg[i] == 1) {
        root = i;
        break;
    }

    dfs(root, -1, 0);
    int mn, mx;
    bool has_odd = false;
    for (auto &x: lens) {
        if (x & 1) has_odd = true;
    }
    mn = has_odd ? 3 : 1;

    mx = n-1;
    for (int i = 0; i < n; ++i) {
        if (deg[i] == 1) {
            pdeg[g[i][0]]++;
        }
    }
    for (int i = 0; i < n; ++i) {
        if (pdeg[i]) mx -= pdeg[i]-1;
    }
    cout << mn << ' ' << mx << '\n';

    return 0;
}
