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
        ll d, k;
        cin >> d >> k;
        ll a, b, INF = d+100;
        {
            ll l = 0, r = INF;
            while (l+1 < r) {
                ll m = (l+r)/2;
                if ((m*k) <= d && 2ll*(m*k)*(m*k) <= d*d) {
                    l = m;
                } else {
                    r = m;
                }
            }
            a = l*k;
        }
        {
            ll l = 0, r = INF;
            while (l+1 < r) {
                ll m = (l+r)/2;
                if ((a+m*k) <= d && a*a+(a+m*k)*(a+m*k) <= d*d) {
                    l = m;
                } else {
                    r = m;
                }
            }
            b = a+l*k;
        }
        ll cnt = a/k + b/k;
        cout << (cnt % 2 ? "Ashish" : "Utkarsh") << '\n';
    }
    return 0;
}
