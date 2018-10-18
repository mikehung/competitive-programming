#include <bits/stdc++.h>

using namespace std;

const int MAX = (int) 2e5+5;
int n, k;
long long a[MAX];
map<long long, long long> L, R;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> k;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        ++R[a[i]];
    }
    long long ans = 0;
    --R[a[0]];
    ++L[a[0]];
    for (int i = 1; i < n-1; ++i) {
        --R[a[i]];
        if (a[i] % k == 0 && L.count(a[i]/k) && R.count(a[i]*k))
            ans += L[a[i]/k] * R[a[i]*k];
        ++L[a[i]];
    }
    cout << ans << '\n';
    return 0;
}
