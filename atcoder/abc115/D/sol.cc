#include <bits/stdc++.h>

using namespace std;

const int MAX = 52;
long long n, x;
long long sz[MAX], dp[MAX];

long long calc(long long n, long long x)
{
    if (x < 0) return 0;
    if (n == 0) return 1;
    if (x == 0) return 0;
    if (x+1 >= sz[n]) return dp[n];
    long long an = calc(n-1, x-1);
    if (x >= sz[n]/2) {
        an++;
        if (x > sz[n]/2)
            an += calc(n-1, x-sz[n]/2-1);
    }
    return an;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> x;
    x--;
    dp[0] = sz[0] = 1;
    for (int i = 1; i < MAX; ++i) {
        sz[i] = sz[i-1] * 2 + 3;
        dp[i] = dp[i-1] * 2 + 1;
    }
    cout << calc(n, x) << endl;
    return 0;
}
