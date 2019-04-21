#include <bits/stdc++.h>

using namespace std;

long long n, h;

bool ok(vector<long long> &b)
{
    sort(b.rbegin(), b.rend());
    long long hh = 0, sz = b.size();
    for (int i = 0; i < sz; i += 2) {
        if (i+1 < sz) {
            hh += max(b[i], b[i+1]);
        } else {
            hh += b[i];
        }
    }
    return hh <= h;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> h;
    vector<long long> a(n);
    for (auto &v: a) cin >> v;
    int lo = 1, hi = n, mid;
    while (lo < hi) {
        mid = lo + (hi-lo+1) / 2;
        vector<long long> b(a.begin(), a.begin()+mid);
        if (!ok(b)) {
            hi = mid-1;
        } else {
            lo = mid;
        }
    }
    cout << lo << endl;
    return 0;
}
