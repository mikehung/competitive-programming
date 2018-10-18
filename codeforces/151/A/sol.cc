#include <bits/stdc++.h>
using namespace std;

#ifdef DEBUG
    #define dbg(...) fprintf(stderr, __VA_ARGS__)
#else
    #define dbg(...)
#endif
int n, k, l, c, d, p, nl, np;

int main()
{
    cin >> n >> k >> l >> c >> d >> p >> nl >> np;
    cout << min(k*l/nl, min(c*d, p/np)) / n << '\n';

    return 0;
}
