#include <bits/stdc++.h>

using namespace std;

long long n, nums = 1, ops, mx, cur;
set<int> s;

long long get_ops(long long x)
{
    if (x < 2) return 0;
    long long base = 1, cnt = 0;
    while (base < x) {
        ++cnt;
        base *= 2;
    }
    if (base != x || (base == x && s.size() > 1)) {
        ++cnt;
    }
    return cnt;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n;
    for (long long i = 2; i*i <= n; ++i) {
        long long cnt = 0;
        while (n % i == 0) {
            ++cnt;
            n /= i;
        }
        if (cnt) {
            nums *= i;
            mx = max(mx, cnt);
            s.insert(cnt);
        }
    }
    if (n > 1) {
        nums *= n;
        mx = max(mx, 1LL);
        s.insert(1);
    }
    cout << nums << ' ' << get_ops(mx) << '\n';
    return 0;
}
