#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, c25 = 0, c50 = 0;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        int x;
        cin >> x;
        if (x == 25) {
            ++c25;
        } else if (x == 50) {
            --c25;
            ++c50;
        } else if (x == 100) {
            if (c50 && c25) {
                --c50;
                --c25;
            } else {
                c25 -= 3;
            }
        }
        if (c25 < 0 || c50 < 0) {
            cout << "NO\n";
            return 0;
        }
    }
    cout << "YES\n";
    return 0;
}
