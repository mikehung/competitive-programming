#include <bits/stdc++.h>

using namespace std;

const int MAX = (int) 2e5+5;
int n, m, mn, par[MAX], rnk[MAX];
long long a[MAX];
typedef tuple<long long, int, int> T;
priority_queue<T, vector<T>, greater<T>> q;

int find(int x)
{
    if (par[x] != x) {
        par[x] = find(par[x]);
    }
    return par[x];
}

int merge(int x, int y)
{
    x = find(x), y = find(y);
    if (x != y) {
        if (rnk[x] < rnk[y]) swap(x, y);
        par[y] = x;
        if (rnk[x] == rnk[y]) rnk[x]++;
        return 1;
    }
    return 0;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> m;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        par[i] = i;
        if (a[mn] > a[i]) mn = i;
    }
    for (int i = 0; i < n; ++i) if (i != mn) {
        q.push(make_tuple(a[i] + a[mn], i, mn));
    }
    int x, y;
    long long w;
    for (int i = 0; i < m; ++i) {
        cin >> x >> y >> w;
        --x, --y;
        q.push(make_tuple(w, x, y));
    }
    int edge = 0;
    long long ans = 0;
    while (edge != n-1) {
        tie(w, x, y) = q.top();
        q.pop();
        if (merge(x, y)) {
            ans += w;
            ++edge;
        }
    }
    cout << ans << '\n';
    return 0;
}
