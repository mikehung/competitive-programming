#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, a1, b1, c1, a2, b2, c2, mn = 0;
    cin >> n >> a1 >> b1 >> c1 >> a2 >> b2 >> c2;
    if (a1 > a2+c2) {
        mn = a1 - (a2+c2);
    } else if (b1 > b2+a2) {
        mn = b1 - (b2+a2);
    } else if (c1 > c2+b2) {
        mn = c1 - (c2+b2);
    }
    cout << mn << ' ' << min(a1, b2) + min(b1, c2) + min(c1, a2) << '\n';
    return 0;
}
