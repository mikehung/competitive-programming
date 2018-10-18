#include <bits/stdc++.h>
using namespace std;

#ifdef DEBUG
    #define dbg(...) fprintf(stderr, __VA_ARGS__)
#else
    #define dbg(...)
#endif

int a, b, gcd, q, lo, hi;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> a >> b >> q;
    gcd = __gcd(a, b);
    vector<int> factors;
    long long i;
    for (i = 1; i*i < gcd; ++i) {
        if (gcd % i == 0) {
            factors.push_back(i);
            factors.push_back(gcd/i);
        }
    }
    if (i*i == gcd) {
        factors.push_back(i);
    }
    sort(factors.begin(), factors.end());
    while (q--) {
        cin >> lo >> hi;
        auto lit = lower_bound(factors.begin(), factors.end(), lo);
        auto hit = upper_bound(factors.begin(), factors.end(), hi);
        if (lit == factors.end() || lit == hit) {
            cout << -1 << '\n';
        } else if (hit == factors.end()) {
            cout << factors.back() << '\n';
        } else {
            cout << *(--hit) << '\n';
        }
    }
    return 0;
}
