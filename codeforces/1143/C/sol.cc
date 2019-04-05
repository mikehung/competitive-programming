#include <bits/stdc++.h>

using namespace std;

const int MAX = (int) 1e5+11;
int n, c[MAX], p[MAX], ok[MAX];
vector<int> g[MAX];

void calc(int u)
{
    if (c[u] == 0) ok[u] = 1;
    if (p[u] != -1 && c[u] == 0) {
        ok[p[u]] = 1;
    }
    for (auto v: g[u]) calc(v);
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n;
    int root;
    for (int i = 1; i <= n; ++i) {
        cin >> p[i] >> c[i];
        if (p[i] != -1) g[p[i]].push_back(i);
        else root = i;
    }
    calc(root);
    bool has = false;
    for (int i = 1; i <= n; ++i) if (!ok[i]) {
        cout << i << ' ';
        has = true;
    }
    if (!has) cout << -1;
    cout << endl;
    return 0;
}
