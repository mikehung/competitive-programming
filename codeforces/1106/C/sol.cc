#include <bits/stdc++.h>

using namespace std;

const int MAX = (int) 3e5+11;
int n, a[MAX];
long long ans;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n;
    for (int i = 0; i < n; ++i) cin >> a[i];
    sort(a, a+n);
    for (int i = 0, j = n-1; i < j; ++i, --j) {
        long long x = a[i] + a[j];
        ans += x * x;
    }
    cout << ans << endl;
    return 0;
}
