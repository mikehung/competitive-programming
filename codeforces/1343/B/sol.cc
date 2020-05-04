#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int tt;
    cin >> tt;
    while (tt--) {
        int n;
        cin >> n;
        if (n % 4) {
            cout << "NO\n";
        } else {
            cout << "YES\n";
            int all = 0;
            for (int i = 1; i <= n/2; ++i) {
                cout << i*2 << ' ';
                all += i*2;
            }
            for (int i = 0; i < n/2-1; ++i) {
                cout << i*2+1 << ' ';
                all -= i*2+1;
            }
            cout << all << "\n";
        }
    }
    return 0;
}
