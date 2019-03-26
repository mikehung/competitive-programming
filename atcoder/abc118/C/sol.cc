#include <bits/stdc++.h>

using namespace std;

int gcd(int a, int b)
{
    if (!b) return a;
    return gcd(b, a%b);
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    int ans = 0;
    while (n--) {
        int x;
        cin >> x;
        ans = gcd(ans, x);
    }
    cout << ans << endl;
    return 0;
}
