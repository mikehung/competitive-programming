#include <bits/stdc++.h>

using namespace std;

const int MAX = 5204;
int n, a[MAX][MAX];
map<char, int> m;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    for (int i = 0; i < 10; ++i) m[i+'0'] = i;
    for (int i = 10; i < 16; ++i) m[i-10+'A'] = i;

    cin >> n;
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; j += 4) {
            char ch;
            cin >> ch;
            a[i][j] = (m[ch] >> 3 & 1);
            a[i][j+1] = (m[ch] >> 2 & 1);
            a[i][j+2] = (m[ch] >> 1 & 1);
            a[i][j+3] = (m[ch] >> 0 & 1);
        }
    }

    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            a[i][j] += a[i-1][j] + a[i][j-1] - a[i-1][j-1];
        }
    }

    for (int x = n; x >= 1; --x) if (n % x == 0) {
        bool ok = true;
        for (int i = 1; i <= n && ok; i += x) {
            for (int j = 1; j <= n && ok; j += x) {
                int v = a[i+x-1][j+x-1] -
                        a[i-1][j+x-1] -
                        a[i+x-1][j-1] +
                        a[i-1][j-1];
                if (v != 0 && v != x*x)
                    ok = false;
            }
        }
        if (ok) {
            cout << x << endl;
            return 0;
        }
    }
    return 0;
}
