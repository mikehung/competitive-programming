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
    int T;
    long long n, k, m, d1, d2, w1, w2, w3;
    cin >> T;
    while (T--) {
        cin >> n >> k >> d1 >> d2;
        if (n % 3) {
            puts("no");
            continue;
        }
        m = min(k, n / 3);
        if ((k + 2LL*d1 + d2) % 3 == 0) {
            w1 = (k + 2LL*d1 + d2) / 3;
            w2 = w1 - d1;
            w3 = w2 - d2;
            if (w1 >= 0 && w2 >= 0 && w3 >= 0 && w1 <= m && w2 <= m && w3 <= m) {
                dbg("1. %lld %lld %lld\n", w1, w2, w3);
                puts("yes");
                continue;
            }
        }
        if ((k + 2LL*d1 - d2) % 3 == 0) {
            w1 = (k + 2LL*d1 - d2) / 3;
            w2 = w1 - d1;
            w3 = w2 + d2;
            if (w1 >= 0 && w2 >= 0 && w3 >= 0 && w1 <= m && w2 <= m && w3 <= m) {
                dbg("2. %lld %lld %lld\n", w1, w2, w3);
                puts("yes");
                continue;
            }
        }
        if ((k - 2LL*d1 + d2) % 3 == 0) {
            w1 = (k - 2LL*d1 + d2) / 3;
            w2 = w1 + d1;
            w3 = w2 - d2;
            if (w1 >= 0 && w2 >= 0 && w3 >= 0 && w1 <= m && w2 <= m && w3 <= m) {
                dbg("3. %lld %lld %lld\n", w1, w2, w3);
                puts("yes");
                continue;
            }
        }
        if ((k - 2LL*d1 - d2) % 3 == 0) {
            w1 = (k - 2LL*d1 - d2) / 3;
            w2 = w1 + d1;
            w3 = w2 + d2;
            if (w1 >= 0 && w2 >= 0 && w3 >= 0 && w1 <= m && w2 <= m && w3 <= m) {
                dbg("4. %lld %lld %lld\n", w1, w2, w3);
                puts("yes");
                continue;
            }
        }
        puts("no");
    }
    return 0;
}
