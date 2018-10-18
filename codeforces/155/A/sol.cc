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
    int n, cnt = 0, x, mx, mn;
    cin >> n;
    cin >> x;
    mx = mn = x;
    for (int i = 1; i < n; ++i) {
        cin >> x;
        if (x > mx) {
            mx = x;
            ++cnt;
        } else if (x < mn) {
            mn = x;
            ++cnt;
        }
    }
    cout << cnt << '\n';

    return 0;
}
