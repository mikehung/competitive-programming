#include <bits/stdc++.h>

using namespace std;

typedef vector<long long> RT;
typedef vector<RT> MT;
const int MOD = (int) 1e9+7;
long long n, m;

MT mul(const MT &a, const MT &b)
{
    MT c(m, RT(m));
    for (int i = 0; i < m; ++i) for (int j = 0; j < m; ++j) {
        long long v = 0;
        for (int k = 0; k < m; ++k) {
            v += a[i][k] * b[k][j];
            v %= MOD;
        }
        c[i][j] = v;
    }
    return c;
}

void pm(const MT &a)
{
    cerr << "matrix: \n";
    for (int r = 0; r < m; ++r) {
        for (int c = 0; c < m; ++c) {
            cerr << a[r][c] << ' ';
        }
        cerr << endl;
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> m;
    if (n < m) {
        cout << 1 << endl;
        return 0;
    }
    n -= m;
    MT a(m, RT(m)), b(m, RT(m));

    a[0][0] = a[0][m-1] = 1;
    for (int r = 0; r < m; ++r) if (r) {
        a[r][r-1] = 1;
    }
    for (int r = 0; r < m; ++r) {
        b[r][r] = 1;
    }
    // pm(a);

    while (n) {
        if (n & 1) {
            b = mul(a, b);
        }
        a = mul(a, a);
        n >>= 1;
    }

    long long ans = b[0][0];
    for (int i = 0; i < m; ++i) {
        ans += b[0][i];
        ans %= MOD;
    }
    // pm(b);
    cout << ans << '\n';

    return 0;
}
