#include <bits/stdc++.h>
using namespace std;

#ifdef DEBUG
    #define dbg(...) fprintf(stderr, __VA_ARGS__)
#else
    #define dbg(...)
#endif

int main()
{
    long long all, x, y, z, a, b, c;
    cin >> x >> y >> z;
    all = sqrt(x * y * z);
    a = all / x;
    b = all / y;
    c = all / z;
    cout << 4 * (a + b + c) << '\n';
    return 0;
}
