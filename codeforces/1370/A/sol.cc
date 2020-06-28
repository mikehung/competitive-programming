#include <bits/stdc++.h>

using namespace std;

int calc(int n)
{
    long long an = 1;
    for (long long x = 3; x*x <= n; x += 2) {
        if (n % x == 0) {
            an = max(an, max(x, n/x));
        }
    }
    return an;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int a = n, b = n-1;
        cout << (a % 2 ? b/2 : a/2) << '\n';
    }
    return 0;
}
