#include <bits/stdc++.h>

using namespace std;

const int MAX = 33;
long long n, k, a, b;
map<long long, int> cnt1, cnt;
long long m2[MAX];

long long calc(long long lo, long long hi)
{
    if (lo == hi) {
        if (cnt1.count(lo)) return b * cnt1[lo];
        else return a;
    }
    // burn
    long long sz = (hi - lo + 1), ans;
    auto lit = cnt.upper_bound(lo-1), hit = cnt.upper_bound(hi);
    long long x = 0;
    if (hit != cnt.begin()) {
        --hit;
        if (lit != cnt.begin()) {
            --lit;
            x = hit->second - lit->second;
        }
        else x = hit->second;
    }
    if (x) ans = min(calc(lo, lo+sz/2-1) + calc(lo+sz/2, hi), b * x * sz);
    else ans = a;
    return ans;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    m2[0] = 1;
    for (int i = 1; i < MAX; ++i) m2[i] = 2ll * m2[i-1];
    cin >> n >> k >> a >> b;
    long long x = 0;
    for (int i = 0; i < k; ++i) {
        cin >> x;
        ++cnt1[x];
        ++cnt[x];
    }
    x = 0;
    for (auto kv: cnt) {
        cnt[kv.first] += x;
        x = cnt[kv.first];
    }
    cout << calc(m2[0], m2[n]) << endl;
    return 0;
}
