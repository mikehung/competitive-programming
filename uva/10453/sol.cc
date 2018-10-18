#include <bits/stdc++.h>
using namespace std;

#ifdef DEBUG
    #define dbg(...) fprintf(stderr, __VA_ARGS__)
#else
    #define dbg(...)
#endif

const int MAX = 1005;
int dp[MAX][MAX];
string s;

void dump(int i, int j)
{
    if (i >= j) {
        if (i == j) cout << s[i];
        return;
    }
    if (s[i] == s[j]) {
        cout << s[i];
        dump(i+1, j-1);
        cout << s[j];
    } else if (dp[i][j] == dp[i+1][j]+1) {
        cout << s[i];
        dump(i+1, j);
        cout << s[i];
    } else {
        cout << s[j];
        dump(i, j-1);
        cout << s[j];
    }
}

int main()
{
    while (cin >> s) {
        int n = s.size();
        for (int i = 0; i < n; ++i) {
            memset(dp[i], 0, sizeof(dp[i]));
        }
        for (int i = 0; i < n; ++i) {
            dp[i][i] = 0;
        }
        for (int d = 1; d < n; ++d) {
            for (int i = 0, j = i+d; j < n; ++i, ++j) {
                if (s[i] == s[j]) {
                    dp[i][j] = dp[i+1][j-1];
                } else if (dp[i+1][j] < dp[i][j-1]) {
                    dp[i][j] = dp[i+1][j] + 1;
                } else {
                    dp[i][j] = dp[i][j-1] + 1;
                }
            }
        }
        cout << dp[0][n-1] << ' ';
        dump(0, n-1);
        cout << '\n';
    }
    return 0;
}
