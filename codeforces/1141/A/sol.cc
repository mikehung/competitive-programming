#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, m;
    cin >> n >> m;
    if (m % n) {
        cout << -1 << endl;
        return 0;
    }
    m /= n;
    int an = 0;
    while (m % 2 == 0) ++an, m /= 2;
    while (m % 3 == 0) ++an, m /= 3;
    cout << (m == 1 ? an : -1) << endl;

    return 0;
}
