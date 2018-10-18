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
    int n;
    double ans = 0;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        double p;
        cin >> p;
        if (p)
            ans += p/100.;
    }
    cout << fixed << setprecision(12) << (ans/(double) n) * 100 << '\n';

    return 0;
}
