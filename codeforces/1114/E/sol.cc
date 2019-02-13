#include <bits/stdc++.h>

using namespace std;

int n, q_cnt;

int read()
{
    int r;
    cin >> r;
    return r;
}

int q1(int x)
{
    cout << "? " << x << endl;
    ++q_cnt;
    return read();
}

int q2(int x)
{
    cout << "> " << x << endl;
    ++q_cnt;
    return read();
}

void ans(int xn, int d)
{
    int x1 = xn - (n-1)*d;
    cout << "! " << x1 << " " << d << endl;
}

int gcd(int x, int y)
{
    if (!y) return x;
    return gcd(y, x % y);
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n;

    // find first 0
    int lo = 0, hi = 1e9, mid, r;
    while (lo < hi) {
        mid = lo + (hi - lo) / 2;
        r = q2(mid);
        if (r == 1) {
            lo = mid + 1;
        } else {
            hi = mid;
        }
    }

    mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
    vector<int> perm(n);
    iota(perm.begin(), perm.end(), 1);
    shuffle(perm.begin(), perm.end(), rng);

    int xn = lo;
    vector<int> diffs;
    for (int i = 0; i < n && q_cnt < 60; ++i) {
        diffs.push_back(xn - q1(perm[i]));
    }

    int d = 0;
    for (auto &kd: diffs) {
        d = gcd(d, kd);
    }
    ans(xn, d);

    return 0;
}
