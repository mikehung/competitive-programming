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
        int n;
        cin >> n;
        for (int i = 0; i < n; ++i) {
            cout << (i+1)%n+1 << ' ';
        }
        cout << '\n';
    }
    return 0;
}
