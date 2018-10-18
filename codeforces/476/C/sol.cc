#include <bits/stdc++.h>
using namespace std;

#ifdef DEBUG
    #define dbg(...) fprintf(stderr, __VA_ARGS__)
#else
    #define dbg(...)
#endif

const int MOD = (int) 1e9+7;

int main()
{
    long long a, b, V, K;
    cin >> a >> b;
    V = (b*(b-1)/2) % MOD;
    K = (a + b*((((a+1)*a)/2)%MOD)%MOD) % MOD;
    cout << (V*K) % MOD << '\n';
    return 0;
}
