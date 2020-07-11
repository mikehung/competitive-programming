#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int c2 = 0, c3 = 0;
        while (n % 2 == 0) {
            c2++;
            n /= 2;
        }
        while (n % 3 == 0) {
            c3++;
            n /= 3;
        }
        if (n > 2 || c2 > c3) {
            cout << -1 << '\n';
        } else {
            cout << c2 + 2*(c3-c2) << '\n';
        }

    }
    return 0;
}
