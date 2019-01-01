// TLE
#include <bits/stdc++.h>

using namespace std;

const int M = 998244353, MAX = (int) 1e5 + 5;
int n, k;
vector<int> digs;
long long cnt[MAX];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> k;
    for (int i = 0; i < k; ++i) {
        int x;
        cin >> x;
        digs.push_back(x);
    }
    sort(digs.begin(), digs.end());
    cnt[0] = 1;
    for (int i = 0; i < n/2; ++i) {
        for (int j = MAX-1; j >= 0; --j) {
            long long v = 0;
            if (j <= digs.back()) {
                for (auto dig: digs) {
                    if (j >= dig)
                    (v += cnt[j - dig]) %= M;
                }
            } else {
                for (auto dig: digs) {
                    (v += cnt[j - dig]) %= M;
                }
            }
            cnt[j] = v;
        }
    }
    long long ans = 0;
    for (int i = 0; i < MAX; ++i) {
        ans += 1ll * cnt[i] * cnt[i];
        ans %= M;
    }
    cout << ans << '\n';
    return 0;
}
