#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    long long a, b, lcm = 1e18+11, k = 1e18+11, cnd_lcm, cnd_k;
    cin >> a >> b;
    if (a > b) swap(a, b);
    if (b % a == 0) {
        cout << 0 << endl;
        return 0;
    }
    long long d = b - a;
    vector<long long> X, Y;
    for (long long i = 1; i*i <= d; ++i) if (d % i == 0) {
        X.push_back(i);
        if (i*i < d) Y.push_back(d/i);
    }
    while (Y.size()) {
        X.push_back(Y.back());
        Y.pop_back();
    }
    for (auto x: X) {
        if (a % x == 0) {
            cnd_lcm = a / x * b;
            if (cnd_lcm <= lcm) {
                lcm = cnd_lcm;
                k = 0;
            }
        } else {
            cnd_k = x - (a % x);
            cnd_lcm = (a+cnd_k) / x * (b+cnd_k);
            if (cnd_lcm < lcm) {
                lcm = cnd_lcm;
                k = cnd_k;
            } else if (cnd_lcm == lcm) {
                k = min(k, cnd_k);
            }
        }
    }
    cout << k << endl;
    return 0;
}
