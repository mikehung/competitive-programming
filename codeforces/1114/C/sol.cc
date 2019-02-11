#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    long long n, b;
    cin >> n >> b;
    map<long long, int> f;
    for (long long i = 2; i*i <= b; ++i) if (b % i == 0) {
        int cnt = 0;
        while (b % i == 0) {
            ++cnt;
            b /= i;
        }
        f[i] = cnt;
    }
    if (b > 1) {
        f[b] = 1;
    }
    long long ans = 1e18;
    for (auto &kv: f) {
        long long v = kv.first, nn = n, cnt = 0;
        while (nn >= v) {
            cnt += nn / v;
            nn /= v;
        }
        ans = min(ans, cnt/kv.second);
    }
    cout << ans << endl;
    return 0;
}
