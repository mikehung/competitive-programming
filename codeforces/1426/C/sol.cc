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
        int an = n-1, mx = min(63244+11, n);
        for (int i = 1; i < min(an, mx); ++i) {
            int cur = (n-1)/(i+1);
            if (an > i+cur) {
                an = i+cur;
            }
        }
        cout << an << '\n';
    }
    return 0;
}
