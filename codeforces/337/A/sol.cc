#include <bits/stdc++.h>
using namespace std;

#ifdef DEBUG
    #define dbg(...) fprintf(stderr, __VA_ARGS__)
#else
    #define dbg(...)
#endif

const int MAX = 1000;
int n, m, a[MAX];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> m;
    for (int i = 0; i < m; ++i)
        cin >> a[i];
    sort(a, a+m);
    int ans = INT_MAX;
    for (int i = 0; i+n-1 < m; ++i) {
        ans = min(ans, a[i+n-1]-a[i]);
    }
    cout << ans << '\n';

    return 0;
}
