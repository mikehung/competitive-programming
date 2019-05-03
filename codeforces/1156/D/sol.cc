#include <bits/stdc++.h>

using namespace std;

const int MAX = 2e5+11;
vector<int> g0[MAX], g1[MAX];
int n, cc0[MAX], cnt0[MAX], cc1[MAX], cnt1[MAX];

void dfs(int *cc, vector<int> *g, int u, int val)
{
    cc[u] = val;
    for (auto &v: g[u]) if (cc[v] == 0) {
        dfs(cc, g, v, val);
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n;
    int x, y, v;
    for (int i = 0; i < n-1; ++i) {
        cin >> x >> y >> v;
        --x, --y;
        if (v) {
            g1[x].push_back(y);
            g1[y].push_back(x);
        } else {
            g0[x].push_back(y);
            g0[y].push_back(x);
        }
    }

    v = 1;
    for (int i = 0; i < n; ++i) if (cc0[i] == 0) {
        dfs(cc0, g0, i, v++);
    }

    v = 1;
    for (int i = 0; i < n; ++i) if (cc1[i] == 0) {
        dfs(cc1, g1, i, v++);
    }

    for (int i = 0; i < n; ++i) {
        cnt0[cc0[i]]++;
        cnt1[cc1[i]]++;
    }

    long long an = 0;
    for (int i = 1; i <= n; ++i) {
        if (cnt0[i]) an += 1ll * cnt0[i] * (cnt0[i]-1);
        if (cnt1[i]) an += 1ll * cnt1[i] * (cnt1[i]-1);
    }
    for (int i = 0; i < n; ++i) {
        if (cnt0[cc0[i]] && cnt1[cc1[i]])
            an += (1ll*cnt0[cc0[i]]-1) * (1ll*cnt1[cc1[i]]-1);
    }
    cout << an << endl;
    return 0;
}
