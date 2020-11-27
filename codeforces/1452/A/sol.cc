#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int tt;
    cin >> tt;
    while (tt--) {
        int a, b;
        cin >> a >> b;
        if (a > b) swap(a, b);
        if (b == a || b == a+1) cout << a + b << '\n';
        else cout << 2*b-1 << '\n';
    }
    return 0;
}
