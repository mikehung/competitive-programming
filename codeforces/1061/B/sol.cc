#include <bits/stdc++.h>

using namespace std;

const int MAX = 1e5 + 112;
int n, m, a[MAX];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    long long all = 0;
    cin >> n >> m;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        all += a[i];
    }
    sort(a, a+n);
    int mx = a[n-1], ai = 0, mi = 1;
    while (ai < n && mi <= mx) {
        if (a[ai] >= mi) {
            ++mi;
        }
        ++ai;
    }
    cout << all - n - mx + mi - 1 << '\n';
    return 0;
}
