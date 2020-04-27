#include <bits/stdc++.h>

using namespace std;

vector<string> digits = {"1110111", "0010010", "1011101", "1011011", "0111010", "1101011", "1101111", "1010010", "1111111", "1111011"};

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, k;
    cin >> n >> k;
    vector<string> str(n);
    vector<vector<int>> dist(n, vector<int>(10));
    for (int i = 0; i < n; ++i) {
        cin >> str[i];
        for (int d = 0; d < 10; ++d) {
            for (int b = 0; b < 8; ++b) {
                char x = str[i][b], y = digits[d][b];
                if (x == '1' && y == '0') {
                    dist[i][d] = -1;
                    break;
                } else if (x == '0' && y == '1') {
                    dist[i][d]++;
                }
            }
        }
    }

    vector<vector<bool>> dp(n+1, vector<bool>(k+1));
    dp[n][0] = 1;
    for (int i = n; i > 0; --i) {
        for (int j = 0; j <= k; ++j) if (dp[i][j]) {
            // transfer s[i-1] to d
            for (int d = 0; d < 10; ++d) {
                if (dist[i-1][d] != -1 && dist[i-1][d]+j <= k) {
                    dp[i-1][dist[i-1][d]+j] = 1;
                }
            }
        }
    }

    if (dp[0][k] == 0) {
        cout << "-1\n";
        return 0;
    }
    for (int i = 0; i < n; ++i) {
        for (int d = 9; d >= 0; --d) {
            if (dist[i][d] != -1 && k >= dist[i][d] && dp[i+1][k-dist[i][d]]) {
                cout << d;
                k -= dist[i][d];
                break;
            }
        }
    }
    cout << '\n';
    return 0;
}
