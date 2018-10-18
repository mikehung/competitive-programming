#include <bits/stdc++.h>
using namespace std;

#ifdef DEBUG
    #define dbg(...) fprintf(stderr, __VA_ARGS__)
#else
    #define dbg(...)
#endif

int n, m, ans;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> m;
    for (int a = 0; a < 1005; ++a) {
        for (int b = 0; b < 1005; ++b) {
            if (a*a+b == n && a+b*b == m)
                ans++;
        }
    }
    cout << ans << '\n';

    return 0;
}
