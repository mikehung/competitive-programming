#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int y, k, n;
    cin >> y >> k >> n;
    int a = y % k;
    if (!a) a = k;
    else a = k - a;
    bool ok = false;
    for (int i = a; i + y <= n; i += k) {
        ok = true;
        cout << i << ' ';
    }
    if (!ok) cout << -1;
    cout << '\n';

    return 0;
}
