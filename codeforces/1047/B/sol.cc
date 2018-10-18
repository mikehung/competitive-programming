#include <bits/stdc++.h>
using namespace std;

#ifdef DEBUG
    #define dbg(...) fprintf(stderr, __VA_ARGS__)
#else
    #define dbg(...)
#endif

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    int x, y, ans = 0;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> x >> y;
        ans = max(ans, x+y);
    }
    cout << ans << '\n';

    return 0;
}
