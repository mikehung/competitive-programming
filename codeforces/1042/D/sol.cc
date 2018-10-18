#include <bits/stdc++.h>
using namespace std;

#ifdef DEBUG
    #define dbg(...) fprintf(stderr, __VA_ARGS__)
#else
    #define dbg(...)
#endif

const int N_MAX = (int) 2*1e5+5;
long long n, k, a[N_MAX], p[N_MAX], s[N_MAX], bit[N_MAX];

int lowbit(int i) {
    return i & (-i);
}

int read(int pos)
{
    int res = 0;
    for (int i = pos+1; i; i -= lowbit(i)) {
        res += bit[i];
    }
    return res;
}

void update(int pos, int val=1) {
    for (int i = pos+1; i <= n+2; i += lowbit(i)) {
        bit[i] += val;
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> k;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
        s[i] = p[i] = p[i-1] + a[i];
    }
    sort(s, s+n+1);
    int un = unique(s, s+n+1) - s, pos;
    long long ans = n * (n+1) / 2;
    for (int j = 0; j <= n; ++j) {
        pos = upper_bound(s, s+un, p[j] - k) - s - 1;
        ans -= read(pos);
        pos = upper_bound(s, s+un, p[j]) - s - 1;
        update(pos, 1);
    }
    cout << ans << '\n';

    return 0;
}
