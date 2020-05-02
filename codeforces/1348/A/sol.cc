#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--) {
        ll a = 0, b = 0;
        int n;
        cin >> n;
        for (int i = 1; i < n/2; ++i) {
            a += 1ll<<i;
        }
        for (int i = n/2; i < n; ++i) {
            b += 1ll<<i;
        }
        a += 1ll<<n;
        cout << a - b << '\n';
    }
    return 0;
}
