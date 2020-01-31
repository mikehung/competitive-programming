#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t, n;
    cin >> t;
    while (t--) {
        cin >> n;
        if (n % 2) {
            cout << 7;
            n -= 3;
        }
        while (n) {
            cout << 1;
            n -= 2;
        }
        cout << endl;
    }
    return 0;
}
