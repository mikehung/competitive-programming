#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, x;
    long long k;
    cin >> n;
    while (n--) {
        cin >> k >> x;
        cout << 9LL * (k-1) + x << '\n';
    }
    return 0;
}
