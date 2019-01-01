#include <bits/stdc++.h>

using namespace std;

const int M = 998244353;
int n;
string a;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> n >> a;
    if (n == 1) {
        cout << 1 << '\n';
        return 0;
    } else if (n == 2) {
        cout << 3 << '\n';
        return 0;
    }

    bool same = true;
    for (int i = 1; i < n; ++i) if (a[i] != a[0]) {
        same = false;
        break;
    }
    if (same) {
        cout << (1ll * n * (n+1) / 2) % M << '\n';
        return 0;
    }
    long long ans = 0;
    int i = 1, j = n - 2;
    while (a[i] == a[0]) ++i;
    while (a[j] == a[n-1]) --j;
    int c1 = i, c2 = n-1-j;
    if (a[0] == a[n-1]) {
        ans = 1ll * (c1+1) * (c2+1);
    } else {
        ans = c1 + c2 + 1;
    }
    cout << ans % M << '\n';
    return 0;
}
