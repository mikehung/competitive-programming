#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int k;
    cin >> k;
    int n = 2000;
    int a = k + n;

    cout << n << '\n';
    cout << -1;
    --n;
    for (int i = 0; i < n; ++i) {
        cout << ' ';
        if (i < a % n) cout << a / n + 1;
        else cout << a / n;
    }
    cout << endl;
    return 0;
}
