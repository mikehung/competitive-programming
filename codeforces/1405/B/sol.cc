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
        int n;
        cin >> n;
        vector<ll> a(n);
        for (auto &it: a) cin >> it;
        ll an = 0, neg = 0;
        for (int i = n-1; i >= 0; --i) {
            neg += a[i];
            if (neg > 0) {
                an += neg;
                neg = 0;
            }
        }
        cout << an << '\n';
    }
    return 0;
}
