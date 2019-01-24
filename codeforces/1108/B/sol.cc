#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, mx = 1;
    map<int, int> d;
    cin >> n;
    while (n--) {
        int x;
        cin >> x;
        ++d[x];
        mx = max(mx, x);
    }
    for (int i = 1; i <= mx; ++i) if (mx % i == 0) {
        if (--d[i] == 0) {
            d.erase(i);
        }
    }
    cout << mx << ' ' << d.rbegin()->first << '\n';
    return 0;
}
