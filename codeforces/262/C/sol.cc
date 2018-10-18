#include <bits/stdc++.h>
using namespace std;

#ifdef DEBUG
    #define dbg(...) fprintf(stderr, __VA_ARGS__)
#else
    #define dbg(...)
#endif

const int MAX = (int) 1e5+123;
int m, n, q1 = MAX, q2 = MAX, dp[MAX], Left[MAX];
map<int, int> cnt;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> m;
    for (int i = 0; i < m; ++i) {
        int q;
        cin >> q;
        if (q < q1) {
            q2 = q1;
            q1 = q;
        } else if (q < q2) {
            q2 = q;
        }
    }
    cin >> n;
    for (int i = 0; i < n; ++i) {
        int x;
        cin >> x;
        ++cnt[x];
    }
    for (int i = 0; i < MAX; ++i) {
        dp[i] = i;
        if (i >= q1) {
            if (dp[i] >= q1 + dp[max(0, i-q1-2)]) {
                dp[i] = q1 + dp[max(0, i-q1-2)];
                Left[i] = 2 - ((i-q1) % 3);
            }
        }
        if (i >= q2) {
            if (dp[i] >= q2 + dp[max(0, i-q2-2)]) {
                dp[i] = q2 + dp[max(0, i-q2-2)];
                Left[i] = 2 - ((i-q2) % 3);
            }
        }
    }
    long long ans = 0, l = 0;
    for (auto it = cnt.rbegin(); it != cnt.rend(); ++it) {
        it->second -= l;
        ans += it->first * dp[it->second];
        l = it->second;
    }
    cout << ans << '\n';

    return 0;
}
