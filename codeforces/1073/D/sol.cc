#include <bits/stdc++.h>

using namespace std;

const int MAX = 2e5+123;
int n, a[MAX];
long long x, ans, cur, cnt;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> x;
    for (int i = 0; i < n; ++i)
        cin >> a[i];
    while (true) {
        cur = cnt = 0;
        for (int i = 0; i < n; ++i) {
            if (cur + a[i] <= x) {
                cur += a[i];
                ++cnt;
            }
        }
        if (!cnt) {
            cout << ans << '\n';
            return 0;
        }
        long long run = x / cur;
        x -= cur * run;
        ans += cnt * run;
    }
    return 0;
}
