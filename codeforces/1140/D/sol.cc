#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    long long ans = 0;
    cin >> n;
    for (int i = 2; i < n; ++i)
        ans += i * (i+1);
    cout << ans << endl;
    return 0;
}
