#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, pos = 0, neg = 0;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        int x;
        cin >> x;
        if (x > 0) pos++;
        if (x < 0) neg++;
    }
    if (pos >= (n+1)/2) cout << 1 << endl;
    else if (neg >= (n+1)/2) cout << -1 << endl;
    else cout << 0 << endl;
    return 0;
}
