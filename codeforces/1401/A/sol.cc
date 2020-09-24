#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        if (n > k) {
            cout << (n+k)%2 << '\n';
        } else {
            cout << k-n << '\n';
        }
    }
    return 0;
}
