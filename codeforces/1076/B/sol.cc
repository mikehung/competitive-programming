#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    long long n, ans = 0;

    cin >> n;
    if (n & 1) {
        ans = 1;
        long long i;
        bool found = false;
        for (i = 3; i * i <= n; i += 2) {
            if (n % i == 0) {
                found = true;
                break;
            }
        }
        if (!found) n = 0;
        else n -= i;
    }
    cout << ans + n/2 << '\n';
    return 0;
}
