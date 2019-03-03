#include <bits/stdc++.h>

using namespace std;

const int NMAX = 5111;
int n, m, cnt[NMAX], train[NMAX];

int dist(int x, int y)
{
    if (y < x) y += n;
    return y - x;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> m;
    int src, dst;
    for (int i = 1; i <= m; ++i) {
        cin >> src >> dst;
        cnt[src]++;
        if (!train[src]) {
            train[src] = dst;
        } else if (dist(src, dst) < dist(src, train[src])) {
            train[src] = dst;
        }
    }
    for (int i = 1; i <= n; ++i) {
        int mx = 0;
        for (int j = 1; j <= n; ++j) if (cnt[j]) {
            mx = max(mx, (cnt[j]-1)*n + dist(i, j) + dist(j, train[j]));
        }
        cout << mx << ' ';
    }
    cout << '\n';
    return 0;
}
