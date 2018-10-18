#include <bits/stdc++.h>
using namespace std;

#ifdef DEBUG
    #define dbg(...) fprintf(stderr, __VA_ARGS__)
#else
    #define dbg(...)
#endif

const int N_MAX = 205, K_MAX = 35;
int n, K, d[N_MAX], dp[N_MAX][K_MAX], S[N_MAX][K_MAX], sum[N_MAX][N_MAX];

int cal(int i, int j)
{
    int res = 0, mid = (i+j)/2;
    for (int k = i; k <= j; ++k) {
        res += abs(d[k] - d[mid]);
    }
    return res;
}

int main()
{
    int chain = 1;
    while (scanf("%d %d", &n, &K) && n && K) {
        for (int i = 0; i < N_MAX; ++i) {
            d[i] = 0;
            for (int j = 0; j < K_MAX; ++j) {
                dp[i][j] = S[i][j] = 0;
            }
            for (int j = 0; j < N_MAX; ++j) {
                sum[i][j] = 0;
            }
        }
        for (int i = 1; i <= n; ++i) {
            scanf("%d", d+i);
        }
        for (int i = 1; i <= n; ++i) {
            for (int j = i; j <= n; ++j) {
                sum[i][j] = cal(i, j);
            }
        }
        for (int i = 1; i <= n; ++i) {
            dp[i][1] = sum[1][i];
            S[i][1] = (1+i)/2;
        }
        for (int k = 2; k <= K; ++k) {
            for (int i = 1; i <= k; ++i) {
                dp[i][k] = 0;
                S[i][k] = i;
            }
            for (int i = 1; i <= n; ++i) {
                int min_v = INT_MAX, min_s = -1;
                for (int s = 1; s <= i-1; ++s) {
                    if (min_v > dp[s][k-1] + sum[s+1][i]) {
                        min_v = dp[s][k-1] + sum[s+1][i];
                        min_s = (s+1+i)/2;
                    }
                }
                dp[i][k] = min_v;
                S[i][k] = min_s;
            }
        }
        dbg("d\n");
        for (int i = 1; i <= n; ++i)
            dbg("%d ", d[i]);
        dbg("\ndp\n");
        for (int k = 1; k <= K; ++k) {
            for (int i = 1; i <= n; ++i) {
                dbg("%d ", dp[i][k]);
            }
            dbg("\n");
        }
        dbg("S\n");
        for (int k = 1; k <= K; ++k) {
            for (int i = 1; i <= n; ++i) {
                dbg("%d ", S[i][k]);
            }
            dbg("\n");
        }

        printf("Chain %d\n", chain++);
    }
    return 0;
}
