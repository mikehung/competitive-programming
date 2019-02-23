#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int q;
    cin >> q;
    while (q--) {
        long long n, a, b;
        cin >> n >> a >> b;
        if (2*a < b) {
            cout << n * a << '\n';
        } else {
            cout << n / 2 * b + (n & 1) * a << '\n';
        }
    }
    return 0;
}
