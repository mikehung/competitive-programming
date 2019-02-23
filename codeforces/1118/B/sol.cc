#include <bits/stdc++.h>

using namespace std;

const int MAX = (int) 2e5+11;
int n, a[MAX], odd[MAX], even[MAX], all, ans;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
        all += a[i];
    }
    for (int i = 1; i <= n; ++i) {
        odd[i] += odd[i-1];
        even[i] += even[i-1];
        if (i & 1) {
            odd[i] += a[i];
        } else {
            even[i] += a[i];
        }
    }
    for (int i = 1; i <= n; ++i) {
        int v = all - a[i];
        if (v & 1) continue;
        v /= 2;
        if (v == even[n] - even[i] + odd[i-1]) ans++;
    }
    cout << ans << '\n';

    return 0;
}
