#include <bits/stdc++.h>
using namespace std;

#ifdef DEBUG
    #define dbg(...) fprintf(stderr, __VA_ARGS__)
#else
    #define dbg(...)
#endif

const int MAX = 1005;
int n, dp[MAX][MAX];
string s, str[MAX][MAX];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    while (cin >> s) {
        n = s.size();
        for (int i = 0; i < MAX; ++i) {
            for (int j = i; j < MAX; ++j) {
                dp[i][j] = 0;
                str[i][j] = "";
            }
        }
        for (int i = 0; i < n; ++i) {
            dp[i][i] = 1;
            str[i][i] = s[i];
        }
        for (int d = 2; d <= n; ++d) {
            for (int i = 0, j = i+d-1; j < n; ++i, ++j) {
                if (s[i] == s[j]) {
                    dp[i][j] = 2 + dp[i+1][j-1];
                    str[i][j] = s[i] + str[i+1][j-1] + s[j];
                } else {
                    int c1 = dp[i+1][j];
                    int c2 = dp[i][j-1];
                    if (c1 > c2 || (c1 == c2 && str[i+1][j] < str[i][j-1])) {
                        dp[i][j] = c1;
                        str[i][j] = str[i+1][j];
                    } else {
                        dp[i][j] = c2;
                        str[i][j] = str[i][j-1];
                    }
                }
            }
        }
        cout << str[0][n-1] << '\n';
    }

    return 0;
}
