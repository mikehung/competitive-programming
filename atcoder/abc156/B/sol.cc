#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, k;
    cin >> n >> k;
    int an = 0;
    while (n) {
        n /= k;
        an++;
    }
    cout << max(1, an) << '\n';
    return 0;
}
