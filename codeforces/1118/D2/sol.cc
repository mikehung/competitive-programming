#include <bits/stdc++.h>

using namespace std;
int n, m;
vector<int> a;

bool can(int day)
{
    long long cnt = 0;
    for (int i = 0; i < n; ++i) {
        cnt += max(0, a[i] - i/day);
    }
    return cnt >= m;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> m;
    a.resize(n);
    for (auto &v: a) {
        cin >> v;
    }
    sort(a.rbegin(), a.rend());
    int lo = 1, hi = n, mid;
    while (lo < hi) {
        mid = lo + (hi - lo) / 2;
        if (can(mid)) {
            hi = mid;
        } else {
            lo = mid + 1;
        }
    }
    if (can(lo)) {
        cout << lo << '\n';
    } else {
        cout << -1 << '\n';
    }
    return 0;
}
