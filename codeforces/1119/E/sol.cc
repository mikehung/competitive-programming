#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    long long n, x;
    cin >> n;
    long long an = 0, left = 0;
    for (int i = 0; i < n; ++i) {
        cin >> x;
        long long v = min(left, x/2);
        an += v;
        left -= v;
        x -= 2ll * v;
        an += x / 3;
        x %= 3;
        left += x;
    }
    cout << an << endl;
    return 0;
}
