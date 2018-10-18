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
    int x, n = 1;
    cin >> x;
    while ((n*n)/2+1 < x) n += 2;
    if (x == 3) n = 5;
    cout << n << '\n';
    return 0;
}
