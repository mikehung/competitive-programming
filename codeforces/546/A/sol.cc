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
    long long n, k, w, all;
    cin >> k >> n >> w;
    all = (1+w)*w/2*k;
    if (all > n) {
        cout << all - n << '\n';
    } else {
        cout << 0 << '\n';
    }
    return 0;
}
