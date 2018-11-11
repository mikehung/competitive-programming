#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, sum = 0;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        int x;
        cin >> x;
        sum += x;
    }
    if (sum % n)
        cout << n-1 << '\n';
    else
        cout << n << '\n';
    return 0;
}
