#include <bits/stdc++.h>

using namespace std;

int q_cnt;

int q1(int x)
{
    int r;
    ++q_cnt;
    cout << "? " << x << endl;
    cin >> r;
    return r;
}

int q2(int x)
{
    int r;
    ++q_cnt;
    cout << "> " << x << endl;
    cin >> r;
    return r;
}

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
    mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
    cin >> n;
    vector<int> perm(n);
    iota(perm.begin(), perm.end(), 1);
    shuffle(perm.begin(), perm.end(), rng);
    int lo = 0, hi = 1e9;
    while (lo < hi) {
        int mid = lo + (hi - lo) / 2;
        int r = q2(mid);
        if (r == -1) return 0;
        else if (r == 1) lo = mid + 1;
        else hi = mid;
    }
    int x1, xn = lo, i = 0, d = 0;
    set<int> nums;
    for (int i = 0; i < n && d != 1 && q_cnt < 60; ++i) {
        int r = q1(perm[i]);
        d = gcd(d, xn - r);
        nums.insert(r);
    }
    if (i == n) {
        x1 = *nums.begin();
        d = (xn - x1) / (n-1);
    } else {
        x1 = xn - (n-1) * d;
    }
    cout << "! " << x1 << ' ' << d << endl;

    return 0;
}
