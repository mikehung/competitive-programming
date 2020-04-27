#include <bits/stdc++.h>

using namespace std;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int tt, n, a, b, c, d;
    cin >> tt;
    while (tt--) {
        cin >> n >> a >> b >> c >> d;
        int na = n*(a-b);
        int nb = n*(a+b);
        int nc = c-d;
        int nd = c+d;
        cout << ((nb < nc || nd < na) ? "No" : "Yes") << '\n';
    }
    return 0;
}
