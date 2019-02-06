#include <bits/stdc++.h>

using namespace std;

const int MAX = (int) 2e5+12;
long long n, a[MAX], d1, d2, d3;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n;
    for (int i = 0; i < n/2; ++i) {
        cin >> a[n-i];
        if (i) { 
            d1 = a[i];
            d2 = a[n-i] - a[n-i+1];
            d3 = max(d1, d2);
            a[i+1] = d3;
            a[n-i] = a[n-i] - d3;
        }
    }
    for (int i = 1; i <= n; ++i) {
        cout << a[i] << ' ';
    }
    cout << '\n';
    return 0;
}
