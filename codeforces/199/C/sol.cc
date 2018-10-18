#include <bits/stdc++.h>
using namespace std;

long long k, b, n, t, cur = 1;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> k >> b >> n >> t;
    int i = 0;
    while (t >= cur && i <= n) {
        ++i;
        cur = k * cur + b;
    }
    cout << n - i + 1 << '\n';

    return 0;
}
