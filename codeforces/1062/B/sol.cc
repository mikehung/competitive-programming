#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, res1 = 1, res2 = 0, mx = 0;
    vector<int> nums;
    cin >> n;
    for (long long i = 2; i*i <= n; ++i) if (n % i == 0) {
        int cnt = 0;
        res1 *= i;
        while (n % i == 0) {
            ++cnt;
            n /= i;
        }
        mx = max(mx, cnt);
        nums.push_back(cnt);
    }
    if (n > 1) {
        res1 *= n;
        nums.push_back(1);
        mx = max(mx, 1);
    }
    while ((1 << res2) < mx) {
        ++res2;
    }
    for (auto num: nums) if (num < (1 << res2)) {
        ++res2;
        break;
    }
    cout << res1 << ' ' << res2 << '\n';
    return 0;
}
