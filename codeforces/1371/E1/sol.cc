#include <bits/stdc++.h>

using namespace std;

int n, p;
vector<int> a;

bool check(int x)
{
    for (int i = 0; i < n; ++i) {
        if (a[i] > x+i) return false;
    }
    for (int i = 0, j = 0; i < n; ++i) {
        if (a[i] > x+i) return false;
        while (j < n && a[j] <= x+i) ++j;
        int cnt = j-i;
        if (cnt && (cnt % p) == 0) return false;
    }
    return true;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> p;
    a.resize(n);
    for (auto &it: a) cin >> it;
    sort(a.begin(), a.end());

    int mn = a[0];
    for (int i = 0; i < n; ++i) {
        mn = max(mn, a[i]-i);
    }
    if (!check(mn)) {
        cout << 0 << '\n';
        return 0;
    }

    int lo = mn, hi = a[n-1], mid;
    while (lo < hi) {
        mid = lo + (hi-lo+1)/2;
        if (check(mid)) {
            lo = mid;
        } else {
            hi = mid-1;
        }
    }
    cout << lo-mn+1 << '\n';
    for (int i = mn; i <= lo; ++i) {
        cout << i << ' ';
    }
    cout << '\n';

    return 0;
}
