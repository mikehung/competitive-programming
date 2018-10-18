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
    int a, b, c, ans = 5000;
    cin >> a >> b >> c;
    int mx = max(a, max(b, c)), mn = min(a, min(b, c));
    for (int i = mn; i <= mx; ++i) {
        ans = min(ans, abs(a-i)+abs(b-i)+abs(c-i));
    }
    cout << ans << '\n';

    return 0;
}
