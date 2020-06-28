#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--) {
        long long n;
        cin >> n;
        if (n == 1) {
            cout << "FastestFinger\n";
        } else if (n % 2) {
            cout << "Ashishgup\n";
        } else {
            int e = 0, o = 0;
            while (n % 2 == 0) {
                e++;
                n /= 2;
            }
            for (long long i = 3; i*i <= n; i += 2) {
                while (n % i == 0) {
                    n /= i;
                    o++;
                }
            }
            if (n > 1) {
                o++;
            }
            if (o == 0) {
                cout << (e == 1 ? "Ashishgup" : "FastestFinger") << '\n';
            } else {
                cout << ((e == 1 && o == 1) ? "FastestFinger" : "Ashishgup") << '\n';
            }
        }
    }
    return 0;
}
