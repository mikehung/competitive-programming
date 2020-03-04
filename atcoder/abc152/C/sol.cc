#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, mn = 1e9, an = 0;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        int x;
        cin >> x;
        if (x < mn) {
            ++an;
            mn = x;
        }
    }
    cout << an << endl;
    return 0;
}
