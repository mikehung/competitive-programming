#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, m, k;
    cin >> n >> m >> k;
    cout << m*(m-1)/2 << '\n';
    for (int i = 1; i <= m; ++i) {
        for (int j = i+1; j <= m; ++j) {
            if (k)
                cout << j << ' ' << i << '\n';
            else
                cout << i << ' ' << j << '\n';
        }
    }

    return 0;
}
