#include <bits/stdc++.h>

using namespace std;

int gcd(int x, int y)
{
    if (!y) return x;
    return gcd(y, x % y);
}

const int v[] = {
0,
0,
1,
1,
5,
1,
21,
1,
85,
73,
341,
89,
1365,
1,
5461,
4681,
21845,
1,
87381,
1,
349525,
299593,
1398101,
178481,
5592405,
1082401};

void bf(int a)
{
    int ans = 0;
    for (int b = 1; b <= a-1; ++b) {
        ans = max(ans, gcd(a^b, a&b));
    }
    // cerr << a << endl;
    cerr << ans << endl;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int ans[30], x = 1;
    ans[0] = 0;
    for (int i = 1; i < 26; ++i) {
        ans[i] = x + ans[i-1];
        x <<= 1;
    }
    int q, a;
    cin >> q;
    while (q--) {
        cin >> a;
        int zero = 0, one = 0;
        while (a) {
            if (a & 1) one++;
            else zero++;
            a /= 2;
        }
        if (!zero) cout << v[one] << endl;
        else cout << ans[zero+one] << endl;
    }
    return 0;
}
