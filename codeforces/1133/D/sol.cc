#include <bits/stdc++.h>

using namespace std;

int gcd(int x, int y)
{
    if (!y) return x;
    return gcd(y, x%y);
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    vector<int> a(n), b(n);
    for (auto &x: a) cin >> x;
    for (auto &x: b) cin >> x;
    int oth = 0;
    map<pair<int, int>, int> cnt;
    for (int i = 0; i < n; ++i) {
        if (a[i] == 0) {
            if (b[i] == 0) oth++;
            continue;
        }
        if (b[i] == 0) {
            cnt[{0, 0}]++;
        }
        int s = 1;
        if (a[i] > 0 ^ b[i] < 0) s = -1;
        if (a[i] < 0) a[i] *= -1;
        if (b[i] < 0) b[i] *= -1;
        int g = gcd(a[i], b[i]);
        cnt[{a[i]/g, s * b[i]/g}]++;
    }
    int res = 0;
    for (auto &kv: cnt) {
        res = max(res, kv.second);
    }
    cout << oth + res << endl;
    return 0;
}
