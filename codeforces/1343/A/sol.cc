#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    vector<long long> a(35);
    a[0] = 1;
    for (int i = 1; i < 35; ++i) {
        a[i] = a[i-1] + (1ll<<i);
    }
    int tt;
    cin >> tt;
    while (tt--) {
        long long n;
        cin >> n;
        for (int i = 1; i < 35; ++i) {
            if (n % a[i] == 0) {
                cout << n/a[i] << '\n';
                break;
            }
        }
    }
    return 0;
}
