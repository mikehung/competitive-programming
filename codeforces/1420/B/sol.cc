#include <bits/stdc++.h>

using namespace std;
using ll = long long;

ll calc(int x)
{
    return 1ll * x * (x-1) / 2;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        ll an = 0, zero = 0;
        vector<int> a(n);
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
            if (a[i] == 0) zero++;
        }
        an += calc(zero);

        for (int i = 30; i >= 0; --i) {
            int cnt = 0;
            for (auto x: a) {
                if (((x>>i) & 1) && (x>>(i+1)) == 0) {
                    cnt++;
                }
            }
            an += calc(cnt);
        }
        cout << an << '\n';
    }
    return 0;
}
