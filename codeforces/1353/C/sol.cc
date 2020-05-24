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
        int n;
        cin >> n;
        ll an = 0;
        for (ll i = 1; i < n/2+1; ++i) {
            an += i * i * 8;
        }
        cout << an << '\n';
    }
    return 0;
}
