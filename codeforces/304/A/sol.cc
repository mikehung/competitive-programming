#include <bits/stdc++.h>

using namespace std;

int n;
set<int> s;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n;
    int cnt = 0;
    for (int a = 1; a <= n; ++a) for (int b = a; b <= n; ++b) {
        int v = a * a + b * b;
        if (v > n*n) break;
        double sqrt_v = sqrt(v);
        if (floor(sqrt_v) == ceil(sqrt_v)) ++cnt;
    }
    cout << cnt << '\n';

    return 0;
}
