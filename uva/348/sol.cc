#include <bits/stdc++.h>
using namespace std;

#ifdef DEBUG
    #define dbg(...) fprintf(stderr, __VA_ARGS__)
#else
    #define dbg(...)
#endif

const int MAX = 15;
int n, r[MAX], c[MAX], dp[MAX][MAX], s[MAX][MAX];

void dump(int i, int j)
{
    if (i == j) {
        cout << "A" << i+1;
        return;
    }
    cout << "(";
    dump(i, s[i][j]);
    cout << " x ";
    dump(s[i][j]+1, j);
    cout << ")";
}

int main()
{
    int t = 1;
    while (cin >> n && n) {
        for (int i = 0; i < MAX; ++i) {
            for (int j = 0; j < MAX; ++j) {
                dp[i][j] = INT_MAX;
                s[i][j] = 0;
            }
        }
        for (int i = 0; i < n; ++i) {
            cin >> r[i] >> c[i];
            dp[i][i] = 0;
        }
        for (int d = 2; d <= n; ++d) {
            for (int i = 0; i+d-1 < n; ++i) {
                int j = i+d-1;
                for (int k = i; k < j; ++k) {
                    if (dp[i][j] > dp[i][k]+dp[k+1][j]+r[i]*c[k]*c[j]) {
                        dp[i][j] = dp[i][k]+dp[k+1][j]+r[i]*c[k]*c[j];
                        s[i][j] = k;
                    }
                }
            }
        }
        cout << "Case " << t++ << ": ";
        dump(0, n-1);
        cout << '\n';
    }

    return 0;
}
