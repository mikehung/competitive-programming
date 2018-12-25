#include <bits/stdc++.h>

using namespace std;

const int MAX = (int) 1e5 + 112;
int n, a[MAX], l[MAX], r[MAX];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
    }
    a[0] = 0, a[n+1] = INT_MAX;
    for (int i = 1; i <= n; ++i) {
        if (a[i] > a[i-1])
            l[i] = l[i-1] + 1;
        else
            l[i] = 1;
    }
    for (int i = n; i >= 1; --i) {
        if (a[i] < a[i+1])
            r[i] = r[i+1] + 1;
        else
            r[i] = 1;
    }
    int ans = 0;
    for (int i = 1; i <= n; ++i) {
        int v = max(l[i-1], r[i+1]) + 1;
        if (a[i-1] + 1 < a[i+1]) {
            v = max(v, l[i-1] + r[i+1] + 1);
        }
        ans = max(ans, v);
    }
    cout << ans << '\n';
    return 0;
}
