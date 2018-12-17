#include <bits/stdc++.h>

using namespace std;

const int MAX = 212;
int n, k, x, a[MAX];
long long dp[MAX][MAX];

long long calc(int lo, int x)
{
    if (dp[lo][x]) return dp[lo][x];
    int sz = n - lo;
    if (x == 0) {
        return (sz < k) ? 0 : -1;
    }
    if (sz > x * k + k - 1) {
        return -1;
    }
    long long mx = -1;
    for (int i = 0; i < k && lo + i < n; ++i) {
        long long res = calc(lo+i+1, x-1);
        if (res != -1) {
            mx = max(mx, res + a[lo+i]);
        }
    }
    return dp[lo][x] = mx;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> k >> x;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    cout << calc(0, x) << '\n';
    return 0;
}
