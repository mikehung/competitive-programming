#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, r;
    cin >> n >> r;
    if (n < 10) r += 100 * (10 - n);
    cout << r << '\n';
    return 0;
}
