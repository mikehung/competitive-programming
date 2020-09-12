#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--) {
        ll a, b, x, y, n, v1, v2, an1, an2;
        cin >> a >> b >> x >> y >> n;

        v1 = min(n, a-x);
        v2 = min(n-v1, b-y);
        an1 = (a-v1)*(b-v2);

        v2 = min(n, b-y);
        v1 = min(n-v2, a-x);
        an2 = (a-v1)*(b-v2);

        cout << min(an1, an2) << '\n';
    }
    return 0;
}
