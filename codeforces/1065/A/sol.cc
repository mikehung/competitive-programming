#include <bits/stdc++.h>
using namespace std;

#ifdef DEBUG
    #define dbg(...) fprintf(stderr, __VA_ARGS__)
#else
    #define dbg(...)
#endif

long long t, a, b, c, ans, s;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> t;
    while (t--) {
        cin >> s >> a >> b >> c;
        long long cnt = s / c;
        long long free = (cnt / a) * b;
        cout << cnt + free << '\n';
    }

    return 0;
}
