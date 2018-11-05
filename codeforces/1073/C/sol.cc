#include <bits/stdc++.h>

using namespace std;

int n, x, y;
long long d;
string s;

void update(int &sx, int &sy, char ch, int d)
{
    if (ch == 'U')
        sy += d;
    else if (ch == 'D')
        sy -= d;
    else if (ch == 'L')
        sx -= d;
    else
        sx += d;
}

bool ok(int len)
{
    int sx = 0, sy = 0;
    for (int i = len; i < n; ++i) {
        update(sx, sy, s[i], 1);
    }
    int l = 0, r = len;
    while (true) {
        int d = abs(x - sx) + abs(y - sy);
        if (d <= len && ((d & 1) == (len & 1))) {
            return true;
        }
        if (len == 0 || r == n) break;
        update(sx, sy, s[l++], 1);
        update(sx, sy, s[r++], -1);
    }
    return false;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> s >> x >> y;
    d = abs(x) + abs(y);
    if (n < d || ((n & 1) != (d & 1))) {
        cout << -1 << '\n';
        return 0;
    }
    int lo = 0, hi = n, mid;
    while (lo < hi) {
        mid = lo + (hi - lo) / 2;
        if (ok(mid)) {
            hi = mid;
        } else {
            lo = mid + 1;
        }
    }
    cout << lo << '\n';
    return 0;
}
