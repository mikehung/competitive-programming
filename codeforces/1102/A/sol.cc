#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    long long sum = n * (n+1) / 2;
    if (sum & 1) cout << 1 << '\n';
    else cout << 0 << '\n';
    return 0;
}
