#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    long long a, b, ans = 0;
    cin >> a >> b;
    if (a & 1) ans ^= a;
    if (!(b & 1)) ans ^= b;
    if ((((b+1)/2)-(a/2)) & 1) ans |= 1;
    else {
        if (ans & 1) ans -= 1;
    }
    cout << ans << endl;
    return 0;
}
