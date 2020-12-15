#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    ll L;
    cin >> L;
    L -= 12;
    ll an = 1;
    for (ll i = 1; i <= 11; ++i) {
        an = an * (L+12-i) / i;
    }
    cout << an << '\n';
    return 0;
}
