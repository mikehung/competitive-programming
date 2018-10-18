#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    long long n, mx = 0, all = 0;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        long long x;
        cin >> x;
        all += x;
        if (x > mx)
            mx = x;
    }
    cout << max(mx, (all-1)/(n-1)+1) << '\n';

    return 0;
}
