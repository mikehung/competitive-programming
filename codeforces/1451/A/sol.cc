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
        int n, an = 0;
        cin >> n;
        if (n == 1) {
            an = 0;
        } else if (n == 2) {
            an = 1;
        } else if (n == 3) {
            an = 2;
        } else if (n % 2 == 0) {
            an = 2;
        } else {
            an = 3;
        }
        cout << an << '\n';
    }
    return 0;
}
