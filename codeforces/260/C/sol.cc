#include <bits/stdc++.h>
using namespace std;

#ifdef DEBUG
    #define dbg(...) fprintf(stderr, __VA_ARGS__)
#else
    #define dbg(...)
#endif

const int N_MAX = (int) 1e5 + 5;
long long n, mn, s, e, y, a[N_MAX];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> e;
    --e;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        if (!i || a[i] <= a[y]) {
            y = i;
        }
    }
    if (a[y] == a[e]) {
        // y = e;
    }
    mn = a[y];
    s = (n + y + 1) % n;
    dbg("y: %lld, s: %lld, e: %lld\n", y, s, e);
    for (int i = 0; i < n; ++i) {
        if (i == y) {
            a[i] = n * mn + (n + e - s + 1) % n;
        } else {
            a[i] -= mn;
            if (e != y) {
                if (s == e) {
                    if (s == i) {
                        a[i]--;
                    }
                } else if (s < e) {
                    if (s <= i && i <= e) {
                        a[i]--;
                    }
                } else {
                    if (i <= e || s <= i) {
                        a[i]--;
                    }
                }
            }
        }
        cout << a[i] << ' ';
    }
    cout << '\n';
    return 0;
}
