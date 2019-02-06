#include <bits/stdc++.h>

using namespace std;

const int MAX = (int) 1e5 + 5;
int n, x, y, a[MAX];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> x >> y;
    if (x > y) {
        cout << n << '\n';
        return 0;
    }
    int cnt = 0;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        if (a[i] <= x) ++cnt;
    }
    cout << (cnt+1) / 2 << '\n';

    return 0;
}
