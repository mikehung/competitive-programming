#include <bits/stdc++.h>

using namespace std;

const int NMAX = 5111;
int n, m, cnt[NMAX], stop[NMAX], front[NMAX], back[NMAX];

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
        if (!stop[src]) {
            stop[src] = dist(src, dst);
        } else if (dist(src, dst) < stop[src]) {
            stop[src] = min(stop[src], dist(src, dst));
        }
    }
    for (int i = 1; i <= n; ++i) if (cnt[i]) {
        stop[i] += (cnt[i]-1) * n;
    }
    for (int i = n; i; --i) {
        if (!stop[i] && !back[i+1]) back[i] = 0;
        else back[i] = max(stop[i], back[i+1]+1);
    }
    for (int i = 1; i <= n; ++i) if (cnt[i]) {
        front[i] += stop[i] + i;
    }
    for (int i = 1; i <= n; ++i) {
        front[i] = max(front[i], front[i-1]);
    }
    for (int i = 1; i <= n; ++i) if (front[i]) {
        front[i] += n - i - 1;
    }
    for (int i = 1; i <= n; ++i) {
        cout << max(front[i-1], back[i]) << ' ';
    }
    cout << '\n';
    return 0;
}
