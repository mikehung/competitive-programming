#include <bits/stdc++.h>
using namespace std;

#ifdef DEBUG
    #define dbg(...) fprintf(stderr, __VA_ARGS__)
#else
    #define dbg(...)
#endif

const int M_MAX = 15, N_MAX = 105;
int m, n, w[M_MAX][N_MAX], dp[M_MAX][N_MAX], p[M_MAX][N_MAX];

int main()
{
    int i, j;
    while (scanf("%d %d", &m, &n) == 2) {
        for (int r = 1; r <= m; ++r) {
            for (int c = 1; c <= n; ++c) {
                scanf("%d", &w[r][c]);
            }
        }
        for (int c = n-1; c; --c) {
            for (int r = 1; r <= m; ++r) {
                i = r;
                j = r == 1 ? m : r-1;
                if (w[j][c+1] < w[i][c+1] || (j < i && w[j][c+1] == w[i][c+1]))
                    i = j;
                j = r == m ? 1 : r+1;
                if (w[j][c+1] < w[i][c+1] || (j < i && w[j][c+1] == w[i][c+1]))
                    i = j;
                w[r][c] += w[i][c+1];
                p[r][c] = i;
            }
        }
        int idx = 0, mn = INT_MAX;
        for (int r = 1; r <= m; ++r) {
            if (w[r][1] < mn) {
                mn = w[r][1];
                idx = r;
            }
        }
        printf("%d", idx);
        for (int c = 1; c < n; ++c) {
            printf(" %d", p[idx][c]);
            idx = p[idx][c];
        }
        printf("\n%d\n", mn);
    }

    return 0;
}
