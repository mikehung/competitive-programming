#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int a, b, n;
    cin >> a >> b >> n;
    int i = 0;
    for (; i < 10; ++i) {
        if ((a * 10 + i) % b == 0) break;
    }
    if (i == 10) {
        cout << -1 << '\n';
        return 0;
    }
    cout << a << i;
    for (int i = 0; i < n-1; ++i)
        cout << 0;
    cout << '\n';
    return 0;
}
