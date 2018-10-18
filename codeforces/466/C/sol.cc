#include <bits/stdc++.h>
using namespace std;

#ifdef DEBUG
    #define dbg(...) fprintf(stderr, __VA_ARGS__)
#else
    #define dbg(...)
#endif

const int MAX = (int) 5*1e5+123;
int n, a[MAX], v2[MAX];
long long p[MAX];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n;
    if (n < 3) {
        cout << 0 << '\n';
        return 0;
    }
    for (int i = 1; i <= n; ++i)
        cin >> a[i];
    for (int i = 1; i <= n; ++i)
        p[i] = a[i] + p[i-1];
    if (p[n] % 3) {
        cout << 0 << '\n';
        return 0;
    }
    long long v = p[n] / 3, cnt = 0;
    if (v == 0)
        v2[n+1] = -1;
    for (int i = n; i; --i) {
        if (p[i] == v+v)
            v2[i] = v2[i+1] + 1;
        else
            v2[i] = v2[i+1];
    }
    for (int i = 1; i < n; ++i) {
        if (p[i] == v)
            cnt += v2[i+1];
    }
    cout << cnt << '\n';

    return 0;
}
