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
    long long lo, hi;
    cin >> lo >> hi;
    cout << "YES\n";
    for (long long i = lo; i <= hi; i += 2) {
        cout << i << ' ' << i + 1 << '\n';
    }

    return 0;
}
